#include "../includes/Character.hpp"
#include <iostream>
#include "../includes/colors.hpp"

//Constructors
Character::Character() : ICharacter() {
	std::cout << GREEN << "Character default constructor called" << RESET << std::endl;
	_name = "default";
	_filed_inventory = 0;
	_filed_floor = 0;
	for(unsigned int i = 0; i < 4; i++){
		_inventory[i] = NULL;
		_floor[i] = NULL;
	}
}

Character::Character(std::string const &name){
	std::cout << GREEN << "Character constructor called" << RESET << std::endl;
	_name = name;
	_filed_inventory = 0;
	_filed_floor = 0;
	for(unsigned int i = 0; i < 4; i++){
		_inventory[i] = NULL;
		_floor[i] = NULL;
	}
}

Character::Character(Character const & src){
	std::cout << BLUE << "copy constructor called" << RESET << std::endl;
	*this = src;
}

//Destructor
Character::~Character(){
	std::cout << RED << "Character Destructor called" << RESET << std::endl;
	for(int i = 0; i < 4; i++){
		if(_inventory[i] != NULL){
			delete _inventory[i];
		}
		if(_floor[i] != NULL)
			delete _floor[i];
	}
}

//Operator overload
Character &Character::operator=(Character const &src){
	std::cout << PURPLE << "copy assignement operator called" << RESET << std::endl;
	if (this != &src){
		this->_name = src._name;
		this->_filed_inventory = src._filed_inventory;
		this->_filed_floor = src._filed_floor;
		for(int i = 0; i < 4; i++){
			if(_inventory[i] != NULL){
				delete _inventory[i];
				this->_inventory[i] = NULL;
			}
			if(_floor[i] != NULL){
				delete _floor[i];
				this->_floor[i] = NULL;
			}
		}
		for(int i = 0; i < 4; i++){
			if(src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
			if(src._floor[i] != NULL)
				this->_floor[i] = src._floor[i]->clone();
		}
	}
	return *this;
}

//Methods
std::string const &Character::getName() const{
	return _name;
}

void Character::equip(AMateria* m){
	if(m == NULL){
		std::cout << NRED << "Unknown Metaria, cannot equip it" << RESET << std::endl;
		return ;
	}
	if(_filed_inventory < 4){
		for(int i = 0; i < 4; i++){
			if(_inventory[i] == NULL){
				_inventory[_filed_inventory] = m;
				break ;
			}
		}
		_filed_inventory++;
		std::cout << NGREEN << "Metaria " << NYELLOW << m->getType();
		std::cout << NGREEN << " succesfully equiped on " << RESET;
		std::cout << NBLUE << _name << RESET << std::endl;
	}
	else {
		std::cout << NRED << "Inventory full" << RESET << std::endl;
		delete m;
	}
}

void Character::unequip(int idx){
	if(idx < 0 || idx > 4) {
		std::cout << RED << "invalid inventory index to unequip" << RESET << std::endl;
		return ;
	}
	if(_inventory[idx] == NULL) {
		std::cout << RED << "no Metaria equiped on " ;
		std::cout << NRED << idx << RED << " index" <<  RESET << std::endl;
		return ;
	}
	if(_filed_floor > 4) {
		std::cout << RED << "Floor is full of metaria, you cannot drop them anymore" << RESET << std::endl;
		return ;
	}
	else {
		std::cout << NBLUE << _name << BLUE << " has unequiped Metaria n.";
		std::cout << NBLUE << idx << RESET << std::endl;
		_floor[_filed_floor] = _inventory[idx];
		_filed_floor++;
		_inventory[idx] = NULL;
		_filed_inventory--;
	}
}

void Character::use(int idx, ICharacter& target){
	if(idx < 0 || idx > 4) {
		std::cout << RED << "invalid inventory index to use Metaria" << RESET << std::endl;
		return ;
	}
	if(_inventory[idx] == NULL){
	 	std::cout << NRED << _name  << RED << " Has no metarial at ";
		std::cout << NRED << idx << RED << ", he can't attack ";
		std::cout << NRED << target.getName() << RESET << std::endl;
		return ;
	}
	else{
		std::cout << NBLUE << _name << BLUE << " Use ";
		_inventory[idx]->use(target);
	}
}
