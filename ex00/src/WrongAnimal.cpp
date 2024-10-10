#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	_type = "Unknown Wronganimal";
	std::cout << GREEN << "WrongAnimal Default Constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
	_type = type;
	std::cout << GREEN << "WrongAnimal Constructor called with attribute type : " << type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	std::cout << BLUE << "WrongAnimal Copy Constructor called" << RESET << std::endl;
	*this = src; 
}

WrongAnimal::~WrongAnimal(){
	std::cout << RED << "WrongAnimal Destructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const & rhs) {
	std::cout << PURPLE << "WrongAnimal Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	WrongAnimal::set_type(std::string type){
	_type = type;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void	WrongAnimal::makeSound() const {
	std::cout << YELLOW << _type << " is making Wrong animal sound" << RESET << std::endl;
}