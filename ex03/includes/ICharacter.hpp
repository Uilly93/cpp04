#ifndef ICHARACTERE_HPP
#define ICHARACTERE_HPP

#include "AMetaria.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
#include <iostream>

class ICharacter
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif