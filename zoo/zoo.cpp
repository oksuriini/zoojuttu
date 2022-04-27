// zoo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Zoo.h"
#include "Date.h"

int main()
{
    std::cout << "Joo nyt tää toimii";
    Date date(20,3,2004); //Ei tarvi olla "Date date();"
    std::cout << date.toString();

}

Animal* Zoo::add(Animal* a)
{
    return 0;
}

Animal* Zoo::remove(string name)
{
    return nullptr;
}

void Zoo::print()
{
}

void Zoo::printSortedByName()
{
    // is there any difference to print() ???
}

void Zoo::printSortedByAge()
{
}

Zoo::~Zoo()
{
    // delete all existing Animal objects!
}
