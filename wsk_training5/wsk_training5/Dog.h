#pragma once
#include "Animal.h"
#include <string>
#include <iostream>

class Dog :public Animal
{
public:
	int iloscLatek;

	Dog(std::string nazwa_, std::string rasa_, int iloscLatek_) :Animal(nazwa_, rasa_), iloscLatek(iloscLatek_)
	{
	}

	void makeSound()
	{
		std::cout << "Hau hau" << std::endl;
	}

};

