#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap("default", 100, 100, 30)
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << getName() << " constructor called"
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap " << getName() << " copy constructor called"
		<< std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << getName()
		<< " copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(){
		std::cout << "FragTrap " << getName() << " destructor called"
		<< std::endl;
}

void FragTrap::highFivesGuys(void){
	if (!hasHitPoints())
	{
		std::cout << "FragTrap " << getName()
			<< " cannot request high fives because it has no hit points"
			<< std::endl;
		return;
	}
	if (!hasEnergyPoints())
	{
		std::cout << "FragTrap " << getName()
			<< " cannot request high fives because it has no energy points"
			<< std::endl;
		return;
	}
	std::cout << "FragTrap " << getName()
		<< " requests a positive high five!" << std::endl;
}
