#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
	public:

		//Constructors
		Character();
		Character(std::string const &name);
		Character(Character const & src);
		
		//Destructor
		~Character();

		//Operator overload
		Character &operator=(Character const &src);

		//Methods
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		private:
			std::string _name;
			std::size_t	_filed_inventory;
			AMateria	*_inventory[4];
			AMateria	*_floor[20];
			std::size_t	_filed_floor;

};

#endif
