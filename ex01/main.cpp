#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

static void printSection(const std::string& title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	printSection("Construction");
	{
		ScavTrap scoped("Scoped");
	}

	printSection("ScavTrap actions");
	ScavTrap guard("Guard");
	guard.attack("intruder");
	guard.guardGate();
	guard.takeDamage(30);
	guard.beRepaired(10);

	printSection("Polymorphism");
	ClapTrap* polymorphic = new ScavTrap("Polymorphic");
	polymorphic->attack("dummy");
	delete polymorphic;

	printSection("Copy");
	ScavTrap copy(guard);
	ScavTrap assigned("Assigned");
	assigned = guard;
	copy.attack("copy target");
	assigned.guardGate();

	printSection("Base class");
	ClapTrap base("Base");
	base.attack("dummy");

	return (0);
}
