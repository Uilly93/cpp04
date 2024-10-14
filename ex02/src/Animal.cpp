#include "../includes/Animal.hpp"

Animal::Animal(){
	_type = "Unknown animal";
	std::cout << GREEN << "Animal Default Constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type){
	_type = type;
	std::cout << GREEN << "Animal Constructor called with attribute type : " << type << RESET << std::endl;
}

Animal::Animal(const Animal &src){
	std::cout << BLUE << "Animal Copy Constructor called" << RESET << std::endl;
	*this = src; 
}

Animal::~Animal(){
	std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(Animal const & rhs) {
	std::cout << PURPLE << "Animal Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

// void	Animal::set_type(std::string type){
// 	_type = type;
// }

// std::string Animal::getType() const {
// 	return _type;
// }

void	Animal::makeSound() const {
	std::cout << YELLOW << _type << " is making unknown sound" << RESET << std::endl;
}
