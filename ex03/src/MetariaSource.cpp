#include "../includes/colors.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include <iostream>

//Constructors
MateriaSource::MateriaSource() {
	std::cout << GREEN << "MateriaSource Default Constructor called" << RESET << std::endl;
	for(int i = 0; i < 4; i++)
		_materias[i] = NULL;
	_nb = 0;
}

//MateriaSource::MateriaSource(parametric constructor){
//    std::cout << GREEN << "MateriaSource Default Constructor called" << RESET << std::endl;
//}

MateriaSource::MateriaSource(const MateriaSource &src) {
	std::cout << BLUE << "MateriaSource Copy Constructor called" << RESET << std::endl;
	*this = src;
}
//Destructor
MateriaSource::~MateriaSource() {
	std::cout << RED << "MateriaSource Destructor called " << RESET << std::endl;
	for(int i = 0; i < 4; i++){
		if(_materias[i] != NULL){
			delete _materias[i];
		}
	}
}

//Operator Overload
MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	std::cout << PURPLE << "MateriaSource Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
		for(int i = 0; i < 4; i++){
			if(src._materias[i] != NULL){
				this->_materias[i] = src._materias[i]->clone();
				delete _materias[i];
			}
			else
				this->_materias[i] = NULL;
		}
		this->_nb = src._nb;
	}
	return *this;
}

//Methods
void MateriaSource::learnMateria(AMateria* m){
	if(_nb == 4){
		std::cout << RED << "not enough space, cannot learn any other metaria" << RESET << std::endl;
		delete m;
		return;
	}
	for(int i = 0; i < 4; i++){
		if(_materias[i] == NULL){
			_materias[i] = m;
			_nb++;
			std::cout << NBLUE << m->getType() << " Metaria added to Metaria Source!" << RESET << std::endl;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++) {
        if (_materias[i] != 0 && _materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
	std::cout << RED << "This type doesn't matchs any learnt type, the Metaria cannot be created" << RESET << std::endl;
	return NULL;

}
