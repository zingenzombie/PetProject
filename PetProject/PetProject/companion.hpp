//
//  companion.hpp
//  PetProject
//
//  Created by Chase Hap on 8/21/22.
//  Copyright © 2022 Chase Hap. All rights reserved.
//

#ifndef companion_hpp
#define companion_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Companions{
public:
    class Companion{
        void LoadTextures(){
            sf::Image *test = new sf::Image();
            test->loadFromFile("Companions/" + name + "/CharTextures/neutral.png");
            textures.emplace("test", test);
        }
    public:
        Companion(string address){
            ifstream file(address);
            file >> name;
            file >> health;
            file >> age;
            file >> hunger;
            file >> happiness;
            
            LoadTextures();
        }
        string name = "";
        unsigned int health = 0, age = 0, hunger = 0, happiness = 0;
        map<string, sf::Image*> textures;
    };
    
    Companions(string address){
        companions.push_back(new Companion(address));
        activeCompanion = companions.at(0);
    }
    
    vector<Companion*> companions;
    
    Companion* activeCompanion;
};

#endif /* companion_hpp */
