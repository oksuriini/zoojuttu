#include "Shark.h"

Shark::Shark(string name, Date birth, double weight, string species)
{
	setName(name);
	setBirth(birth);
	setWeight(weight);
	setSpecies(species);
}

void Shark::move()
{
	printf("Swoosh swoosh swoosh");
}

void Shark::utter()
{
	printf("blub blub");
}
