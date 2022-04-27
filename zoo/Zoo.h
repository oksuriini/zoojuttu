#pragma once
#include <map>
#include "Animal.h"
class Zoo
{
private:
	map<string, Animal*> animals;
public:
	Animal* add(Animal* a);
	Animal* remove(string name);
	void print();
	void printSortedByName();
	void printSortedByAge();
	~Zoo();
};

