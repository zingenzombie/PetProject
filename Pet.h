//
// Created by Chase Hap on 6/17/22.
//

#ifndef PETPROJECT_PET_H
#define PETPROJECT_PET_H
#include <iostream>

using namespace std;

class Pet {

public:
    Pet(string name, unsigned int health, unsigned int happiness);

private:
    string name = "NoName";
    unsigned int health = 100;
    unsigned int happiness = 100;
};


#endif //PETPROJECT_PET_H
