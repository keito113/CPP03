#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap("default", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << getName() << " constructor called"
		<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap " << getName() << " copy constructor called"
		<< std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap " << getName()
		<< " copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << getName() << " destructor called"
		<< std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (!hasHitPoints())
	{
		std::cout << "ScavTrap " << getName()
			<< " cannot attack because it has no hit points" << std::endl;
		return;
	}
	if (!trySpendEnergyPoint())
	{
		std::cout << "ScavTrap " << getName()
			<< " cannot attack because it has no energy points" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!"
		<< std::endl;
}

void ScavTrap::guardGate(){
	if (!hasHitPoints())
	{
		std::cout << "ScavTrap " << getName()
			<< " cannot enter Gate keeper mode because it has no hit points"
			<< std::endl;
		return;
	}
	if (!hasEnergyPoints())
	{
		std::cout << "ScavTrap " << getName()
			<< " cannot enter Gate keeper mode because it has no energy points"
			<< std::endl;
		return;
	}
	std::cout << "ScavTrap " << getName()
		<< " is now in Gate keeper mode" << std::endl;
}
