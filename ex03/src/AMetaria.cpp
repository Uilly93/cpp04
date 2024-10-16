#include "../includes/AMetaria.hpp"
#include "../includes/colors.hpp"

//Constructor:

AMateria::AMateria(){
	std::cout << GREEN << "AMetaria default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type){
	std::cout << GREEN << "AMetaria constructor called" << RESET << std::endl;
	_type = type;
}
AMateria::AMateria(AMateria const & src){
	std::cout << BLUE << "AMetaria copy constructor called" << RESET << std::endl;
	*this = src;
}

//Destructor:

AMateria::~AMateria(){
	std::cout << RED << "AMetaria destructor called" << RESET << std::endl;
};

//Operator Overload:

AMateria& AMateria::operator=(AMateria const & src){
	std::cout << PURPLE << "copy assignement operator called" << RESET << std::endl;
	if(this != &src){
		this->_type = src._type;
	}
	return *this;
}

std::string const & AMateria::getType() const{
	return _type;
};
