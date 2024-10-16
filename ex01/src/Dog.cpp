#include "../includes/Dog.hpp"

Dog::Dog(): Animal(){
	_type = "Dog";
	this->_brain = new Brain();
	std::cout << GREEN << "Dog Default Constructor called" << RESET << std::endl;
}

Dog::Dog(std::string type): Animal(type){
	_type = type;
	this->_brain = new Brain();
	std::cout << GREEN << "Dog Constructor called with attribute type : " << type << RESET << std::endl;
}

Dog::Dog(const Dog &src): Animal(src){
	std::cout << BLUE << "Dog Copy Constructor called" << RESET << std::endl;
	*this = src; 
}

Dog::~Dog(){
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
	delete _brain;
}

Dog &Dog::operator=(Dog const & rhs) {
	std::cout << PURPLE << "Dog Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain();
		for(unsigned int i = 0; i < 100; i++)
			this->_brain->cpyIdea(i, rhs._brain->getIdea(i));
	}
	return *this;
}

void	Dog::set_type(std::string type){
	_type = type;
}

std::string Dog::getType() const {
	return _type;
}

void	Dog::makeSound() const {
	std::cout << YELLOW << _type << " is barking" << RESET << std::endl;
}

void	Dog::printIdeas() const {
	_brain->printIdeas();
}

void	Dog::setIdeas() {
	_brain->setIdeas();
}

void	Dog::changeIdea(unsigned int i, std::string idea){
	return _brain->cpyIdea(i - 1, idea);
}