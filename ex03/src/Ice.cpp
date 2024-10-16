#include "../includes/colors.hpp"
#include "../includes/Ice.hpp"
#include <iostream>

//Constructors
Ice::Ice() : AMateria() {
	std::cout << GREEN << "Ice Default Constructor called" << RESET << std::endl;
	_type = "ice";
}

//Ice::Ice(parametric constructor){
//    std::cout << GREEN << "Ice Default Constructor called" << RESET << std::endl;
//}

Ice::Ice(const Ice &src) : AMateria(src) {
	std::cout << BLUE << "Ice Copy Constructor called" << RESET << std::endl;
	*this = src;
}
//Destructor
Ice::~Ice() {
	std::cout << RED << "Ice Destructor called " << RESET << std::endl;
}

//Operator Overload
Ice &Ice::operator=(const Ice &src) {
	std::cout << PURPLE << "Ice Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return *this;
}
//Methods
std::string const & Ice::getType() const{
	return _type;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target){
	std::cout << NBLUE << getType() << BLUE << " Metaria on ";
	std::cout << NBLUE << target.getName() << RESET << std::endl;
}