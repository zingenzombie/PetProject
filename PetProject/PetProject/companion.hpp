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
#include "animations.hpp"

using namespace std;

class Companions{
public:
    class Companion{
        void LoadTextures(){
            sf::Image *neutral = new sf::Image();
            neutral->loadFromFile("Companions/" + name + "/CharTextures/neutral.png");
            sf::Texture *neutralTx = new sf::Texture();
            neutralTx->loadFromImage(*neutral);
            textures.emplace("neutral", neutralTx);
            
            sf::Image *sad = new sf::Image();
            sad->loadFromFile("Companions/" + name + "/CharTextures/sad.png");
            sf::Texture *sadTx = new sf::Texture();
            sadTx->loadFromImage(*sad);
            textures.emplace("sad", sadTx);
            
            sf::Image *dead = new sf::Image();
            dead->loadFromFile("Companions/" + name + "/CharTextures/dead.png");
            sf::Texture *deadTx = new sf::Texture();
            deadTx->loadFromImage(*dead);
            textures.emplace("dead", deadTx);
            
            sf::Image *sick = new sf::Image();
            sick->loadFromFile("Companions/" + name + "/CharTextures/sick.png");
            sf::Texture *sickTx = new sf::Texture();
            sickTx->loadFromImage(*sick);
            textures.emplace("sick", sickTx);
        }
        void LoadAnimations(){
            
        }
        
    public:
        Companion(string address){
            ifstream file("Companions/" + address + "/CharConfig.txt");
            file >> name;
            file >> health;
            file >> age;
            file >> hunger;
            file >> happiness;
            
            LoadTextures();
            LoadAnimations();
        }
        
        void SaveCompanion(string address){
            ofstream file("Companions/" + address + "/CharConfig.txt");
            file << name << endl;
            file << health << endl;
            file << age << endl;
            file << hunger << endl;
            file << happiness << endl;
        }
        
        string name = "";
        unsigned int health = 0, hunger = 0, happiness = 0;
        unsigned long age = 0;
        bool active = false;
        map<string, sf::Texture*> textures;
        map<string, Animation*> animations;
    };
    
    Companions(string address){
        ifstream file(address);
        string tmp;
        file >> tmp;
        companions.push_back(new Companion(tmp));
        activeCompanion = companions.at(0);
        activeCompanion->active = true;
    }
    
    void SaveCompanions(){
        for(int i = 0; i < companions.size(); i++){
            companions.at(i)->SaveCompanion(companions.at(i)->name);
        }
    }
    
    vector<Companion*> companions;
    
    Companion *activeCompanion;
};

#endif /* companion_hpp */
