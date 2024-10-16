#ifndef AMETARIA_HPP
#define AMETARIA_HPP

#include <string>

class ICharacter;

class AMateria {
	public:
		//Constructor:

		AMateria(std::string const & type);
		AMateria(AMateria const & src);

		//Destructor:

		virtual ~AMateria();

		//Operator Overload:

		virtual AMateria &operator=(AMateria const & src);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;

	protected:
		AMateria();
		std::string _type;
};

#endif