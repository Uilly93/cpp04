#include "../includes/colors.hpp"
#include "../includes/MetariaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"


//Constructors
MetariaSource::MetariaSource() {
	std::cout << GREEN << "MetariaSource Default Constructor called" << RESET << std::endl;
	for(int i = 0; i < 4; i++)
		_materias[i] = NULL;
	_nb = 0;
}

//MetariaSource::MetariaSource(parametric constructor){
//    std::cout << GREEN << "MetariaSource Default Constructor called" << RESET << std::endl;
//}

MetariaSource::MetariaSource(const MetariaSource &src) {
	std::cout << BLUE << "MetariaSource Copy Constructor called" << RESET << std::endl;
	*this = src;
}
//Destructor
MetariaSource::~MetariaSource() {
	std::cout << RED << "MetariaSource Destructor called " << RESET << std::endl;
}

//Operator Overload
MetariaSource &MetariaSource::operator=(const MetariaSource &src) {
	std::cout << PURPLE << "MetariaSource Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
		for(int i = 0; i < 4; i++){
			if(src._materias[i] != NULL){
				this->_materias[i] = src._materias[i]->clone();
				delete _materias[i];
			}
		}
		this->_nb = src._nb;
	}
	return *this;
}

//Methods
void MetariaSource::learnMateria(AMateria* m){
	if(_nb == 4){
		std::cout << RED << "not enough space, cannot learn any other metaria" << RESET << std::endl;
		return;
	}
	for(int i = 0; i < 4; i++){
		if(_materias[i] != NULL){
			_materias[i] = m;
			_nb ++;
			std::cout << NBLUE << m->getType() << " Metaria added to Metaria Source!" << RESET << std::endl;
			break;
		}
	}
}

AMateria* MetariaSource::createMateria(std::string const & type){
	if(type == "ice")
		return new Ice;
	else if(type == "cure")
		return new Cure;
	else
	 	std::cout << RED << "This type doesn't matchs any existing type, the Metaria cannot be created" << RESET << std::endl;
}
