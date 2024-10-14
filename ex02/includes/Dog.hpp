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
		void	makeSound() const ;
		void			set_type(std::string type);
		std::string		getType() const ;
		void cpyBrain();
		void	printIdeas() const ;
		void	setIdeas();
		void	changeIdea(unsigned int i, std::string idea);

	private:

		//Attribute:
		Brain *_brain;
};

#endif
