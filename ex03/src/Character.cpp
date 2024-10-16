#include "../includes/Character.hpp"
#include <iostream>
#include "../includes/colors.hpp"

//Constructors
Character::Character() : ICharacter() {
	std::cout << GREEN << "Character default constructor called" << RESET << std::endl;
	_name = "default";
	_filed_inventory = 0;
	_filed_floor = 0;
	for(unsigned int i = 0; i < 20; i++){
		if(i < 4)
			_inventory[i] = NULL;
		_floor[i] = NULL;
	}
}

Character::Character(std::string const &name){
	std::cout << GREEN << "Character constructor called" << RESET << std::endl;
	_name = name;
	_filed_inventory = 0;
	_filed_floor = 0;
	for(unsigned int i = 0; i < 20; i++){
		if(i < 4)
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
	std::cout << RED << "Destructor called" << RESET << std::endl;
	for(int i = 0; i < 20; i++){
		if(i < 4 && _inventory[i] != NULL){
			delete _inventory[i];
		}
		if(_floor[i] != NULL){
			delete _floor[i];
		}
	}
}

//Operator overload
Character &Character::operator=(Character const &src){
	std::cout << PURPLE << "copy assignement operator called" << RESET << std::endl;
	if (this != &src){
		this->_name = src._name;
		this->_filed_inventory = src._filed_inventory;
		this->_filed_floor = src._filed_floor;
		for(int i = 0; i < 20; i++){
			if(i < 4){
				if(this->_inventory[i] != NULL)
					delete this->_inventory[i];
			}
			if(this->_floor[i] != NULL)
				delete this->_floor[i];
		}
		for(int i = 0; i < 20; i++){
			if(i < 4){
				if(src._inventory[i] != NULL)
					this->_inventory[i] = src._inventory[i]->clone();
			}
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
	if(_filed_inventory < 4){
		for(int i = 0; i < 4; i++){
			if(_inventory[i] == NULL){
				_inventory[_filed_inventory] = m;
				break ;
			}
		}
		_filed_inventory++;
		std::cout << NGREEN << "Metaria succesfully equiped" << RESET << std::endl;
	}
	else 
		std::cout << NRED << "Inventory full" << RESET << std::endl;
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
	if(_filed_floor < 20) {
		std::cout << RED << "Floor is full of metaria, you cannot drop them anymore" << RESET << std::endl;
		return ;
	}
	else {
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
	if(_inventory[idx] != NULL){
		std::cout << NBLUE << _name << BLUE << " Use ";
		_inventory[idx]->use(target);
	}
	else{
	 	std::cout << NRED << _name  << RED << " Has no metarial at ";
		std::cout << NRED << idx << RED << RESET << std::endl;
	}
}
