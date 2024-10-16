#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"

class Ice : public AMateria{
	public:
		//Constructor
		Ice();
		//Ice(parametric constructor);
		Ice(const Ice &src);

		//Destructor
		virtual ~Ice();

		//Operator Overload
		Ice &operator=(const Ice &src);

		//Methods
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const ;
		void use(ICharacter& target);
};

#endif