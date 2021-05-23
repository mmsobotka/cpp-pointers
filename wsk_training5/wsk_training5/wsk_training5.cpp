#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
	Animal* animal;
	animal = new Dog("Alex", "owczarek", 3);
	animal->makeSound();
	animal->tellName();
	delete animal;
	animal = new Cat(10, "Ala", "Brytyjski");
	animal->makeSound();
	animal->tellName();

	Animal** animals = new Animal * [10];

	for (int i = 0; i < 6; i++)
	{
		std::string nazwaPieska = "Reksio ";
		nazwaPieska += std::to_string(i);
		animals[i] = new Dog(nazwaPieska, "owczarek", i);
	}
	for (int i = 6; i < 10; i++)
	{
		std::string nazwaKotela = "Filemon ";
		nazwaKotela += std::to_string(i);
		animals[i] = new Dog(nazwaKotela, "brytyjski", i);
	}

	for (int i = 0; i < 10; i++)
	{
		animals[i]->tellName();
	}
	delete animal;

	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
	delete[] animals;

}
