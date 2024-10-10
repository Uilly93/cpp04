#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
// #include <iostream>

class Cat : public Animal {
	public :
		//Constructor:
		Cat();
		Cat(std::string name);
		Cat(const Cat & src);
		//Destructor:
		virtual ~Cat();
		//Operator Overload:
		Cat &operator=(Cat const & rhs);
		//Methods:
		virtual void	makeSound() const ;
		void			set_type(std::string type);
		std::string		getType() const ;
};

#endif
