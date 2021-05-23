#include "Animal.h"

Animal::Animal(std::string nazwa_, std::string rasa_) : nazwa(nazwa_), rasa(rasa_)
{
}

void Animal::tellName()
{
	std::cout << "Mam na imie " << nazwa << " i jestem rasy " << rasa << std::endl;
}

