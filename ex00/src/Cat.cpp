#include "../includes/Cat.hpp"

Cat::Cat(): Animal(){
	_type = "Cat";
	std::cout << GREEN << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::Cat(std::string type): Animal(type){
	_type = type;
	std::cout << GREEN << "Cat Constructor called with attribute type : " << type << RESET << std::endl;
}

Cat::Cat(const Cat &src): Animal(src){
	std::cout << BLUE << "Cat Copy Constructor called" << RESET << std::endl;
	*this = src; 
}

Cat::~Cat(){
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(Cat const & rhs) {
	std::cout << PURPLE << "Cat Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	Cat::set_type(std::string type){
	_type = type;
}

std::string Cat::getType() const {
	return _type;
}

void	Cat::makeSound() const {
	std::cout << YELLOW << _type << " is meowing" << RESET << std::endl;
}
