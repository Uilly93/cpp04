#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


int main()
{
	Animal* tab[10];

	std::cout << NGREEN << "----creating Dogs----" << RESET << std::endl;
	for(int i = 0; i < 5; i++){
		tab[i] = new Dog("Dog");
	}

	std::cout << NGREEN << "----creating Cats----" << RESET << std::endl;
	for(int i = 5; i < 10; i++){
		tab[i] = new Cat("Cat");
	}

	for(int i = 0; i < 10; i++){
		tab[i]->makeSound();
	}

	std::cout << NGREEN << "----all animals created----" << RESET << std::endl;
	for(int i = 0; i < 10; i++)
		delete tab[i];

	const Dog* newDog = new Dog("newdog");
	const Dog* cpyDog;
	cpyDog = newDog;
	
	cpyDog->makeSound();
	cpyDog->printIdeas();
	delete newDog;

	std::cout << NGREEN << "---------Deep Copy---------" << RESET << std::endl;
	Dog basic;
	basic.setIdeas();
	basic.changeIdea(100, "WOOF!");
	{
		Dog tmp = basic;
		tmp.printIdeas();
	}
	std::cout << NGREEN << "---------Abstract class---------" << RESET << std::endl;
	// const Animal* error_of_nature = new Animal();
	const Animal* ThisIsOk = new Cat("Chat");
	ThisIsOk->makeSound();
	delete ThisIsOk;

	return 0;
}
