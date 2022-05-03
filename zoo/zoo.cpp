// zoo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Zoo.h"
#include "Date.h"
#include "Animal.h"
#include "Shark.h"
#include "Tiger.h"


int main()
{
    Zoo elaimet;
    Date syntyma = NULL;
    int x = 0;
    while(x != 7){
    std::cout << "Zoo functions: \n";
    std::cout << "1 - Add Tiger\n";
    std::cout << "2 - Add Shark\n";
    std::cout << "3 - Print all animals in the Zoo by their name\n";
    std::cout << "4 - Print all animals in the Zoo by their age\n";
    std::cout << "5 - Remove animal from Zoo by name\n";
    std::cout << "6 - Make all animals move and utter\n";
    std::cout << "7 - Exit\n";

    std::cin >> x;

    switch (x)
    {
    case 1:
    case 2:
    {
        std::cout << "Give the birthdate of the animal: ";
        std::cout << "\nDay: ";
        int paiva;
        std::cin >> paiva;
        std::cout << "\nMonth: ";
        int kuukausi;
        std::cin >> kuukausi;
        std::cout << "\nYear: ";
        int vuosi;
        std::cin >> vuosi;
        syntyma = Date(paiva, kuukausi, vuosi);
        if (x == 1) {
            std::cout << "\nGive the name of Tiger: ";
            string name;
            std::cin >> name;
            std::cout << "\nGive the weight of Tiger: ";
            double weight;
            std::cin >> weight;
            std::cout << "\nGive the species of Tiger: ";
            string species;
            std::cin >> species;
            elaimet.add(new Tiger(name,syntyma,weight,species));
            break;
        }
        else if (x == 2) {
            std::cout << "\nGive the name of Shark: ";
            string name;
            std::cin >> name;
            std::cout << "\nGive the weight of Shark: ";
            double weight;
            std::cin >> weight;
            std::cout << "\nGive the species of Shark: ";
            string species;
            std::cin >> species;
            elaimet.add(new Shark(name, syntyma, weight, species));
            break;
        }
    case 3:
        elaimet.printSortedByName();
        break;
    }
    case 4:
    {
        elaimet.printSortedByAge();
        break;
    }
    case 5:
    {
        std::cout << "\n Give the name of the animal you want to remove";
        string name;
        std::cin >> name;
        elaimet.remove(name);
        break;
    }
    case 6:
    {
        elaimet.print();
        break;
    }
    default:
        break;
    }
    }
}

Animal* Zoo::add(Animal* a)
{
    string key = a->getName();
    animals[key] = a;
    
    return 0;
}

Animal* Zoo::remove(string name)
{
    Animal* tempo = nullptr;
    auto animal = animals.find(name);
    if (animal != animals.end()) {
        tempo = animal->second;
        animals.erase(animal);
    }
    std::cout << tempo->getName() << " sent to the sausage factory\n";
    return nullptr;
}

void Zoo::print()
{
    for (const auto& key : animals) {
        std::cout << key.first << " goes: "; key.second->utter(); std::cout << " and moves: "; key.second->move();
    }
}

void Zoo::printSortedByName()
{
    for (const auto& key : animals) {
        std::cout << key.second->toString();
    }//T‰‰ ja print periaatteessa samat niin emt kai n‰in?
}

void Zoo::printSortedByAge()
{
    map<int, Animal*>agesorted;
    for (const auto& key : animals) {
        Date date = key.second->getBirth();
        agesorted[date.getY()] = key.second;
    }
    for (const auto& avain : agesorted) {
        std::cout << avain.second->toString();
    }
    agesorted.clear();
}

Zoo::~Zoo()
{
    for (const auto& key : animals) {
        std::cout << key.first << " deleted" << endl;
    }
    // delete all existing Animal objects!   
}
