#ifndef IMATERIA_SOURCE_HPP
#define IMATERIA_SOURCE_HPP

#include <iostream>
#include "AMetaria.hpp"
#include "colors.hpp"


class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif