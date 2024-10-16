#include "../includes/colors.hpp"
#include "../includes/Cure.hpp"
#include <iostream>

//Constructors
Cure::Cure() : AMateria() {
	std::cout << GREEN << "Cure Default Constructor called" << RESET << std::endl;
	_type = "cure";
}

// Cure::Cure(std::string &type){
// 	if(type != "cure")
// 		return;
// 	std::cout << GREEN << "Cure Default Constructor called" << RESET << std::endl;
// }

Cure::Cure(const Cure &src) : AMateria(src){
	std::cout << BLUE << "Cure Copy Constructor called" << RESET << std::endl;
	*this = src;
}

//Destructor
Cure::~Cure() {
	std::cout << RED << "Cure Destructor called " << RESET << std::endl;
}

//Operator Overload
Cure &Cure::operator=(const Cure &src) {
	std::cout << PURPLE << "Cure Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return *this;
}

//Methods
std::string const & Cure::getType() const{
	return _type;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target){
		std::cout << NBLUE << getType() << BLUE << " Metaria on ";
		std::cout << NBLUE << target.getName() << RESET << std::endl;
}
