//
//  animations.hpp
//  PetProject
//
//  Created by Chase Hap on 9/10/22.
//  Copyright © 2022 Chase Hap. All rights reserved.
//

#ifndef animations_hpp
#define animations_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <fstream>

using namespace std;

class Animation{
public:
    Animation(string instructionAddress, bool loops, float speed = 24){
        this->loops = loops;
        this->speed = speed;
        
        //write a loop that imports an instruction text file into the forward list. Probably do something like the texture to point to followed by the amount of frames it should be there for.
        
        ifstream file(instructionAddress);
        
    }
    
    void playAnimation(){
        do{
            
        }while(loops);
    }
    
    bool loops;
    float speed;
    forward_list<string> instructions;
};

#endif /* animations_hpp */
