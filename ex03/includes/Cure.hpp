#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"

class Cure : public AMateria{
	public:
		//Constructor
		Cure();
		// Cure(std::string &type);
		Cure(const Cure &src);

		//Destructor
		virtual ~Cure();

		//Operator Overload
		Cure &operator=(const Cure &src);

		//Methods
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif