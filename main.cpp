#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Pet.h"

using namespace std;

int main() {

    LinkedList<Pet*> petList;

    std::cout << "Welcome to Pet Project! Checking for existing pets..." << std::endl;

    ifstream pets("pets.csv");

    if(!pets.is_open()){
        cout << "No pets detected; please enter a new pet." << endl;
        ofstream pets("pets.csv");
        pets << 0 << ",," << endl;
        pets << "PetName,Health,Happiness" << endl;
    }
    else{
        string numPets;
        getline(pets, numPets, ',');
        string dump;
        getline(pets, dump, ',');
        getline(pets, dump, ',');
        getline(pets, dump);
        for (int i = 0; i < stoi(numPets); i++){
            string name;
            string health;
            string happiness;
            getline(pets, name, ',');
            getline(pets, health, ',');
            getline(pets, happiness, ',');
            Pet *tmp = new Pet(name, stoi(health), stoi(happiness));
            petList.AddTail(tmp);
        }
    }


    return 0;
}
