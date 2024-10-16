#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
// #include <iostream>

class Cat : public Animal {
	public :

		//Constructor:
		Cat();
		Cat(std::string type);
		Cat(const Cat & src);

		//Destructor:
		virtual ~Cat();

		//Operator Overload:
		Cat &operator=(Cat const & rhs);

		//Methods:
		void	makeSound() const ;
		void			set_type(std::string type);
		std::string		getType() const ;
		// void	printIdeas() const ;
		void	printIdeas() const ;
		void	setIdeas();
		void	changeIdea(unsigned int i, std::string idea);

	private:

		//Attribute:
		Brain *_brain;
};

#endif
