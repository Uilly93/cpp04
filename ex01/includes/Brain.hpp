#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "../includes/colors.hpp"

class Brain {
	public:

		//Constructors:
		Brain();
		Brain(Brain const &src);

		//Destructor:
		~Brain();

		//Copy Assignement opperator:
		Brain &operator=(Brain const & src);

		//Methods:
		void	setIdeas();
		void	printIdeas() const ;

	private:
		std::string ideas[100];
};

std::string to_string(size_t i);

#endif
