#ifndef METARIA_SOURCE_HPP
#define METARIA_SOURCE_HPP

// #include "AMetaria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource{
	public:
		//Constructor
		MateriaSource();
		//MateriaSource(parametric constructor);
		MateriaSource(const MateriaSource &src);

		//Destructor
		~MateriaSource();

		//Operator Overload
		MateriaSource &operator=(const MateriaSource &src);

		//Methods
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria*	_materias[4];
		std::size_t _nb;
};

#endif