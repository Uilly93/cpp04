#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include "colors.hpp"

class WrongAnimal {
	public:
		
		//Constructors:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		
		//Destructors:
		virtual ~WrongAnimal();
		
		//Operator Overload:
		WrongAnimal &operator=(const WrongAnimal &src);

		//Methods:
		std::string		getType() const ;
		void			set_type(std::string type);
		/* virtual  */void	makeSound() const ;

	protected:
		//Attributes
		std::string _type;
};

#endif