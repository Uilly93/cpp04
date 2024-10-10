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

	// Animal* dog = new Dog("dog");
	// dog->makeSound();

	const Dog* newDog = new Dog("newdog");
	const Dog* cpyDog;//(newDog);
	cpyDog = newDog;
	
	cpyDog->makeSound();
	cpyDog->getIdeas();
	// delete dog;
	// delete cpyDog;
	delete newDog;

	return 0;
}
