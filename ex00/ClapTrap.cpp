#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap()
	: _name("default"),
	  _hitPoint(10),
	  _energyPoint(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " default constructor called"
			  << " (HP: " << _hitPoint
			  << ", EP: " << _energyPoint
			  << ", AD: " << _attackDamage << ")"
			  << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name (name),
	  _hitPoint(10),
	  _energyPoint(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called"
			  << " (HP: " << _hitPoint
			  << ", EP: " << _energyPoint
			  << ", AD: " << _attackDamage << ")"
			  << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoint(other._hitPoint),
	  _energyPoint(other._energyPoint),
	  _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copy constructor called"
			  << " (HP: " << _hitPoint
			  << ", EP: " << _energyPoint
			  << ", AD: " << _attackDamage << ")"
			  << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if(this != &other){
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " copy assignment operator called"
			  << " (HP: " << _hitPoint
			  << ", EP: " << _energyPoint
			  << ", AD: " << _attackDamage << ")"
			  << std::endl;
	return(*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if(_hitPoint == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot attack because it has no hit points"
				  << std::endl;
		return;
	}
	if(_energyPoint == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot attack because it has no energy points"
				  << std::endl;
		return;
	}
	_energyPoint = _energyPoint - 1;
	std::cout << "ClapTrap " << _name
			  << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!"
			  << " (EP left: " << _energyPoint << ")"
			  << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(_hitPoint == 0){
		std::cout << "ClapTrap " << _name
				  << " already has no hit points"
				  << std::endl;
		return;
	}
	if(amount >= _hitPoint){
		_hitPoint = 0;
	} else{
		_hitPoint = _hitPoint - amount;
	}
	std::cout << "ClapTrap " << _name
			  << " takes " << amount << " points of damage,"
			  << " remaining hit points: " << _hitPoint
			  << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount){
	const unsigned int maxValue = std::numeric_limits<unsigned int>::max();
	if(_hitPoint == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot repair because it has no hit points"
				  << std::endl;
		return;
	}
	if(_energyPoint == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot repair because it has no energy points"
				  << std::endl;
		return;
	}
	_energyPoint = _energyPoint - 1;
	if(amount > maxValue - _hitPoint){
		_hitPoint = maxValue;
	} else{
		_hitPoint += amount;
	}
	std::cout << "ClapTrap " << _name
			  << " repairs itself for " << amount << " hit points,"
			  << " current hit points: " << _hitPoint
			  << " (EP left: " << _energyPoint << ")"
			  << std::endl;
	return;
}
