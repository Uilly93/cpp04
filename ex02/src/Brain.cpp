#include "../includes/Brain.hpp"
// #include <cstddef>
#include <sstream>

	Brain::Brain(){
		std::cout << GREEN << "Default Brain constructor called" << RESET << std::endl;
		// setIdeas();
	};
	Brain::Brain(Brain const &src){
		std::cout << GREEN << "Copy Brain constructor called" << RESET << std::endl;
		*this = src;
	};

	//Destructor:
	Brain::~Brain(){
		std::cout << RED << "Brain destructor called" << RESET << std::endl;
	};

	//Copy Assignement opperator:
	Brain &Brain::operator=(Brain const & src){
		if(this != &src){
			for(unsigned int i = 0; i < 100; i++)
				this->ideas[i] = src.ideas[i];
		}
		return *this;
	};

	void	Brain::setIdeas(){
		for(std::size_t i(0); i < 100 ;i++)
			ideas[i] = to_string(i + 1);
	};

	void	Brain::printIdeas() const {
		for(unsigned int i = 0; i < 100; i++)
			std::cout << NYELLOW << "idea N." << i + 1 << " is " << NGREEN << ideas[i] << RESET << std::endl;	
	};

	std::string to_string(size_t i)
	{	
		std::stringstream s;
		s << i;
		return s.str();
	}

	std::string Brain::getIdea(unsigned int i) const{
		return ideas[i];
	};

	void Brain::cpyIdea(unsigned int i, std::string idea) {
		ideas[i] = idea;
	}

