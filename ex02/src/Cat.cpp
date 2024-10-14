#include "../includes/Cat.hpp"

Cat::Cat(): Animal(){
	_type = "Cat";
	_brain = new Brain();
	std::cout << GREEN << "Cat Default Constructor called" << RESET << std::endl;
}

Cat::Cat(std::string type): Animal(type){
	_type = type;
	_brain = new Brain();
	std::cout << GREEN << "Cat Constructor called with attribute type : " << type << RESET << std::endl;
}

Cat::Cat(const Cat &src): Animal(src){
	std::cout << BLUE << "Cat Copy Constructor called" << RESET << std::endl;
	*this = src; 
}

Cat::~Cat(){
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
	delete _brain;
}

Cat &Cat::operator=(Cat const & rhs) {
	std::cout << PURPLE << "Cat Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain();
		for(unsigned int i = 0; i < 100; i++)
			this->_brain->cpyIdea(i, rhs._brain->getIdea(i));
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

void	Cat::printIdeas() const {
	_brain->printIdeas();
};

void	Cat::setIdeas() {
	_brain->setIdeas();
}

void	Cat::changeIdea(unsigned int i, std::string idea){
	return _brain->cpyIdea(i - 1, idea);
}