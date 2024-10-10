#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
// #include <iostream>

class Dog : public Animal {
	public :
	
		//Constructor:
		Dog();
		Dog(std::string type);
		Dog(const Dog & src);

		//Destructor:
		virtual ~Dog();

		//Operator Overload:
		Dog &operator=(Dog const & rhs);

		//Methods:
		virtual void	makeSound() const ;
		void			set_type(std::string type);
		std::string		getType() const ;
		void	getIdeas() const ;

	private:

		//Attribute:
		Brain *_brain;
};

#endif
