#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <limits>

static void printSection(const std::string& title)
{
	std::cout << "\n==== " << title << " ====" << std::endl;
}

static void printStep(const std::string& detail)
{
	std::cout << "-- " << detail << std::endl;
}

static void triggerSelfAssignment(ScavTrap& trap)
{
	ScavTrap* sameObject = &trap;
	trap = *sameObject;
}

int main()
{
	printSection("Construction and Destruction Chaining");
	{
		printStep("Create a scoped ScavTrap to observe base->derived construction");
		ScavTrap scoped("Scoped");
		printStep("Leaving scope triggers derived->base destruction");
		(void)scoped;
	}

	printSection("ScavTrap Initial Values Through Black-Box Behavior");
	ScavTrap sentinel("Sentinel");
	printStep("HP 100 allows the trap to survive 99 damage");
	sentinel.takeDamage(99);
	sentinel.attack("first intruder");
	printStep("The last point of damage disables actions");
	sentinel.takeDamage(1);
	sentinel.attack("second intruder");
	sentinel.guardGate();

	printSection("ScavTrap Energy Starts At 50");
	ScavTrap battery("Battery");
	for (int i = 0; i < 50; ++i)
		battery.attack("drain target");
	battery.attack("depleted target");
	battery.guardGate();

	printSection("Repair Reuses ClapTrap Safety");
	ScavTrap mechanic("Mechanic");
	mechanic.takeDamage(40);
	mechanic.beRepaired(15);
	mechanic.beRepaired(std::numeric_limits<unsigned int>::max());
	mechanic.takeDamage(std::numeric_limits<unsigned int>::max());
	mechanic.takeDamage(1);

	printSection("Virtual Dispatch Through A Base Reference");
	ScavTrap dispatcher("Dispatcher");
	ClapTrap& baseRef = dispatcher;
	baseRef.attack("virtual target");

	printSection("Virtual Destruction Through A Base Pointer");
	printStep("Allocate a ScavTrap as a ClapTrap* and delete it polymorphically");
	ClapTrap* polymorphic = new ScavTrap("Polymorphic");
	delete polymorphic;

	printSection("Copy Construction, Assignment, And Self-Assignment");
	ScavTrap original("Original");
	original.takeDamage(25);
	ScavTrap copied(original);
	printStep("Mutate the original after copying to show independence");
	original.beRepaired(10);
	printStep("Copy still uses the copied state");
	copied.attack("copy target");

	ScavTrap assigned("Assigned");
	assigned.attack("warm-up target");
	printStep("Assign the original state into another ScavTrap");
	assigned = original;
	assigned.guardGate();
	printStep("Force a runtime self-assignment on the assigned object");
	triggerSelfAssignment(assigned);
	assigned.attack("self-check target");

	printSection("Base ClapTrap Still Works");
	ClapTrap base("Base");
	base.attack("dummy");
	base.takeDamage(10);
	base.beRepaired(1);

	printSection("End of ex01 tests");
	return (0);
}
