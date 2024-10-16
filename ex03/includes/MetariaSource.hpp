#ifndef METARIA_SOURCE_HPP
#define METARIA_SOURCE_HPP

#include <cstddef>
#include <iostream>
#include "AMetaria.hpp"
#include "IMateriaSource.hpp"
#include "colors.hpp"


class MetariaSource : IMateriaSource{
	public:
		//Constructor
		MetariaSource();
		//MetariaSource(parametric constructor);
		MetariaSource(const MetariaSource &src);

		//Destructor
		~MetariaSource();

		//Operator Overload
		MetariaSource &operator=(const MetariaSource &src);

		//Methods
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria*	_materias[4];
		std::size_t _nb;
};

#endif