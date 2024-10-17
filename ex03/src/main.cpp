#include "../includes/IMateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include <iostream>
#include "../includes/colors.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Filling Metaria source with 4 metaria:" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "trying to overfill spellbook metaria" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "creating Character \"Georges\" and equiping it with 2 metarias:" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	ICharacter* meme = new Character("Georges");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	meme->equip(tmp);
	tmp = src->createMateria("cure");
	meme->equip(tmp);
	tmp = src->createMateria("ice");
	meme->equip(tmp);
	tmp = src->createMateria("cure");
	meme->equip(tmp);

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Trying to over equip Georges" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	tmp = src->createMateria("ice");
	meme->equip(tmp);
	tmp = src->createMateria("cure");
	meme->equip(tmp);

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Georges Attacking new Character Bob:" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	ICharacter* bob = new Character("Bob");
	ICharacter* me = new Character("me");
	me = meme;
	for(int i = 0; i < 4; i++)
		meme->unequip(i);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Trying to unequip materia n.0 of Georges inventory and attacking Bob" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	me->unequip(0);
	me->use(0, *bob);

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Georges Trying to attack Bob with invalid inventory items" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	me->use(42, *bob);
	me->use(-42, *bob);

	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;
	std::cout << NGREEN << "Destructors calling" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------" << RESET << std::endl;

	// Character bobby = Character("bobby");

	// bobby.equip(tmp);

	// Character hobby = Character(bobby);

	// bobby.unequip(0);

	// hobby.use(0, bobby);


	delete bob;
	delete me;
	delete src;

	return 0;
}
