#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

protected:
	ClapTrap(const std::string& name, unsigned int hp, unsigned int ep,
		unsigned int ad);
	const std::string& getName() const;
	unsigned int getAttackDamage() const;
	bool hasHitPoints() const;
	bool hasEnergyPoints() const;
	bool trySpendEnergyPoint();

public:
	ClapTrap();
	explicit ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
