#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap()
	: _name("default"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for "
			  << _name
			  << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name (name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called"
			  << std::endl;
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

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if(this != &other){
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " copy assignment operator called"
			  << std::endl;
	return(*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if(_hitPoints == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot attack because it has no hit points"
				  << std::endl;
		return;
	}
	if(_energyPoints == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot attack because it has no energy points"
				  << std::endl;
		return;
	}
	_energyPoints = _energyPoints - 1;
	std::cout << "ClapTrap " << _name
			  << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!"
			  << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(_hitPoints == 0){
		std::cout << "ClapTrap " << _name
				  << " already has no hit points"
				  << std::endl;
		return;
	}
	if(amount >= _hitPoints){
		_hitPoints = 0;
	} else{
		_hitPoints = _hitPoints - amount;
	}
	std::cout << "ClapTrap " << _name
			  << " takes " << amount << " points of damage!"
			  << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount){
	const unsigned int maxValue = std::numeric_limits<unsigned int>::max();
	if(_hitPoints == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot repair because it has no hit points"
				  << std::endl;
		return;
	}
	if(_energyPoints == 0){
		std::cout << "ClapTrap " << _name
				  << " cannot repair because it has no energy points"
				  << std::endl;
		return;
	}
	_energyPoints = _energyPoints - 1;
	if(amount > maxValue - _hitPoints){
		_hitPoints = maxValue;
	} else{
		_hitPoints += amount;
	}
	std::cout << "ClapTrap " << _name
			  << " repairs itself and regains " << amount
			  << " hit points!"
			  << std::endl;
	return;
}
