#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string nazwa;
	std::string rasa;

public:
	Animal(std::string nazwa_, std::string rasa_);

	virtual void makeSound() = 0;

	virtual void tellName();

};

