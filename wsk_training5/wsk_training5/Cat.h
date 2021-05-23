#pragma once
#include "Animal.h"
#include <iostream>
#include <string>

class Cat :public Animal
{
public:
	int iloscWasow;

	Cat(int iloscWasow_, std::string nazwa_, std::string rasa_) :Animal(nazwa_, rasa_), iloscWasow(iloscWasow_)
	{
	}

	void makeSound()
	{
		std::cout << "Miau miau" << std::endl;
	}

};

