#include "ClapTrap.hpp"

#include <iostream>
#include <limits>

namespace {

unsigned int saturatingAdd(unsigned int lhs, unsigned int rhs)
{
	const unsigned int maxValue = std::numeric_limits<unsigned int>::max();

	if (rhs > maxValue - lhs)
		return (maxValue);
	return (lhs + rhs);
}

}

ClapTrap::ClapTrap()
	: _name("default"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, unsigned int hp,
	unsigned int ep, unsigned int ad)
	: _name(name),
	  _hitPoints(hp),
	  _energyPoints(ep),
	  _attackDamage(ad)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copy constructor called"
		<< std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " copy assignment operator called"
		<< std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!hasHitPoints())
	{
		std::cout << "ClapTrap " << _name
			<< " cannot attack because it has no hit points" << std::endl;
		return;
	}
	if (!trySpendEnergyPoint())
	{
		std::cout << "ClapTrap " << _name
			<< " cannot attack because it has no energy points" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hasHitPoints())
	{
		std::cout << "ClapTrap " << _name
			<< " already has no hit points" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hasHitPoints())
	{
		std::cout << "ClapTrap " << _name
			<< " cannot repair because it has no hit points" << std::endl;
		return;
	}
	if (!trySpendEnergyPoint())
	{
		std::cout << "ClapTrap " << _name
			<< " cannot repair because it has no energy points" << std::endl;
		return;
	}
	_hitPoints = saturatingAdd(_hitPoints, amount);
	std::cout << "ClapTrap " << _name << " repairs itself and regains "
		<< amount << " hit points!" << std::endl;
}

const std::string& ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

bool ClapTrap::hasHitPoints() const
{
	return (_hitPoints > 0);
}

bool ClapTrap::hasEnergyPoints() const
{
	return (_energyPoints > 0);
}

bool ClapTrap::trySpendEnergyPoint()
{
	if (_energyPoints == 0)
		return (false);
	--_energyPoints;
	return (true);
}
