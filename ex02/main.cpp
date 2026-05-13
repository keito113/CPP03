#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

static void printSection(const std::string& title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	printSection("ScavTrap");
	ScavTrap scav("Scavvy");
	scav.attack("intruder");
	scav.guardGate();

	printSection("FragTrap");
	FragTrap frag("Fraggy");
	frag.attack("target");
	frag.highFivesGuys();

	printSection("Polymorphism");
	ClapTrap* scavBase = new ScavTrap("PolyScav");
	ClapTrap* fragBase = new FragTrap("PolyFrag");
	scavBase->attack("dummy");
	fragBase->attack("dummy");
	delete scavBase;
	delete fragBase;

	printSection("Copy");
	ScavTrap scavCopy(scav);
	ScavTrap scavAssigned("AssignedScav");
	scavAssigned = scav;
	FragTrap fragCopy(frag);
	FragTrap fragAssigned("AssignedFrag");
	fragAssigned = frag;
	scavCopy.attack("copy target");
	fragCopy.highFivesGuys();
	scavAssigned.guardGate();
	fragAssigned.attack("assigned target");

	printSection("Base class");
	ClapTrap base("Base");
	base.attack("dummy");
	base.takeDamage(5);
	base.beRepaired(3);

	return (0);
}
