#include "ClapTrap.hpp"
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

static void triggerSelfAssignment(ClapTrap& trap)
{
	ClapTrap* sameObject = &trap;
	trap = *sameObject;
}

int main()
{
	printSection("Construction");
	ClapTrap defaultTrap;
	ClapTrap alpha("Alpha");

	printSection("Attack drains energy and stops at zero");
	for (int i = 0; i < 11; ++i)
		alpha.attack("training dummy");

	printSection("Damage saturates at zero hit points");
	ClapTrap bravo("Bravo");
	bravo.takeDamage(3);
	bravo.takeDamage(7);
	bravo.takeDamage(1);

	printSection("Destroyed ClapTrap cannot act");
	bravo.attack("intruder");
	bravo.beRepaired(5);

	printSection("Repair restores hit points and drains energy");
	ClapTrap charlie("Charlie");
	charlie.takeDamage(4);
	charlie.beRepaired(2);
	charlie.attack("spare target");

	printSection("Repair is blocked when energy reaches zero");
	ClapTrap hotel("Hotel");
	for (int i = 0; i < 10; ++i)
		hotel.attack("battery drain target");
	hotel.takeDamage(5);
	hotel.beRepaired(1);

	printSection("Repair saturates at unsigned int max");
	ClapTrap delta("Delta");
	delta.beRepaired(std::numeric_limits<unsigned int>::max());
	delta.takeDamage(std::numeric_limits<unsigned int>::max());
	delta.takeDamage(1);

	printSection("Copy constructor creates an independent copy");
	ClapTrap echo("Echo");
	echo.takeDamage(5);
	ClapTrap echoCopy(echo);
	printStep("Original object repairs itself after the copy");
	echo.beRepaired(2);
	printStep("Copied object attacks with the state captured at copy time");
	echoCopy.attack("copy target");

	printSection("Copy assignment and self-assignment");
	ClapTrap foxtrot("Foxtrot");
	ClapTrap golf("Golf");
	foxtrot.takeDamage(6);
	golf.attack("warmup target");
	printStep("Assign the damaged Foxtrot state into Golf");
	golf = foxtrot;
	printStep("Assigned object repairs independently from the source object");
	golf.beRepaired(3);
	printStep("Force a runtime self-assignment on Foxtrot");
	triggerSelfAssignment(foxtrot);
	foxtrot.attack("self-check target");

	printSection("End of ex00 tests");
	(void)defaultTrap;
	return (0);
}
