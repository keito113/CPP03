#include "ClapTrap.hpp"
#include <iostream>

static void printSection(const std::string& title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	printSection("Constructors");
	ClapTrap defaultTrap;
	ClapTrap alpha("Alpha");

	printSection("Basic actions");
	alpha.attack("training dummy");
	alpha.takeDamage(4);
	alpha.beRepaired(2);

	printSection("No hit points");
	ClapTrap bravo("Bravo");
	bravo.takeDamage(10);
	bravo.attack("intruder");
	bravo.beRepaired(1);

	printSection("Copy");
	ClapTrap copy(alpha);
	ClapTrap assigned("Assigned");
	assigned = alpha;
	copy.attack("copy target");
	assigned.attack("assigned target");

	(void)defaultTrap;
	return (0);
}
