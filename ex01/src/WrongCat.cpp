#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	_type = "WrongCat";
	std::cout << GREEN << "WrongCat Default Constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type){
	_type = type;
	std::cout << GREEN << "WrongCat Constructor called with attribute type : " << type << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src){
	std::cout << BLUE << "WrongCat Copy Constructor called" << RESET << std::endl;
	*this = src; 
}

WrongCat::~WrongCat(){
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & rhs) {
	std::cout << PURPLE << "WrongCat Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void	WrongCat::set_type(std::string type){
	_type = type;
}

std::string WrongCat::getType() const {
	return _type;
}

void	WrongCat::makeSound() const {
	std::cout << YELLOW << _type << " is making wrong cat sound" << RESET << std::endl;
}
