#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
	public:
		
		//Constructors:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat const &src);
		
		//Destructors:
		virtual ~WrongCat();
		
		//Operator Overload:
		WrongCat &operator=(const WrongCat &src);

		//Methods:
		std::string		getType() const ;
		void			set_type(std::string type);
		/* virtual  */void	makeSound() const ;
};

#endif