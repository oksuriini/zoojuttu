#include "Tiger.h"

Tiger::Tiger(string name, Date birth, double weight, string species)
{
	setName(name);
	setBirth(birth);
	setWeight(weight);
	setSpecies(species);
}

void Tiger::move()
{
	printf("Stomp stomp stomp");
}

void Tiger::utter()
{
	printf("roar.");
}
