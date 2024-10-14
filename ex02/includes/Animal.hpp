#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "colors.hpp"

class Animal{
	public:

		//Constructor:
		Animal();
		Animal(std::string name);
		Animal(const Animal &src);

		//Destructor:
		virtual ~Animal();

		//Operator Overload:
		virtual Animal &operator=(Animal const & rhs);

		//Member functions:
		virtual void	makeSound() const = 0;
		// void			set_type(std::string type);
		// std::string		getType() const ;

	protected:
		std::string _type;
};

#endif