#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "companion.hpp"
#include <thread>
#include <mutex>

using namespace std;

map<string, sf::Sprite*> SpriteMaker(Companions *companions){
    map<string, sf::Sprite*> sprites;
    
    //Button Sprite setup
    sf::Image buttonImg;
    buttonImg.loadFromFile("Assets/button.png");
    sf::Texture *buttonTx = new sf::Texture();
    buttonTx->loadFromImage(buttonImg);
    sf::Sprite *button = new sf::Sprite();
    button->setTexture(*buttonTx);
    sprites.emplace("button", button);
    
    //ButtonPressed Sprite setup
    sf::Image buttonPressedImg;
    buttonPressedImg.loadFromFile("Assets/buttonPressed.png");
    sf::Texture *buttonPressedTx = new sf::Texture();
    buttonPressedTx->loadFromImage(buttonPressedImg);
    sf::Sprite *buttonPressed = new sf::Sprite();
    buttonPressed->setTexture(*buttonPressedTx);
    sprites.emplace("buttonPressed", buttonPressed);
    
    //ButtonHighlight Sprite setup
    sf::Image buttonHighlightImg;
    buttonHighlightImg.loadFromFile("Assets/buttonHighlight.png");
    sf::Texture *buttonHighlightTx = new sf::Texture();
    buttonHighlightTx->loadFromImage(buttonHighlightImg);
    sf::Sprite *buttonHighlight = new sf::Sprite();
    buttonHighlight->setTexture(*buttonHighlightTx);
    sprites.emplace("buttonHighlight", buttonHighlight);
    
    //Companion sprite setup
    sf::Sprite *comp = new sf::Sprite();
    comp->setTexture(*companions->activeCompanion->textures.find("neutral")->second);
    sprites.emplace("comp", comp);
    
    return sprites;
}

void buttonHover(char buttonState[], sf::Vector2i &mousePos){
    if(mousePos.y >= 500 && mousePos.y <= 800 && mousePos.x >= 0 && mousePos.x <= 500){
        if(mousePos.y >= 700){
            if(mousePos.x >= 250){
                //if(buttonState[5] != 2)
                    buttonState[5] = 1;
            }
            else //if(buttonState[4] != 2)
                buttonState[4] = 1;
        }
        
        else if(mousePos.y >= 600){
            if(mousePos.x >= 250){
                //if(buttonState[3] != 2)
                    buttonState[3] = 1;
            }
            else //if(buttonState[2] != 2)
                buttonState[2] = 1;
        }
        
        else{
            if(mousePos.x >= 250){
                //if(buttonState[1] != 2)
                    buttonState[1] = 1;
            }
            else //if(buttonState[0] != 2)
                buttonState[0] = 1;
        }
    }
}

void drawButtons(map<string, sf::Sprite*> &sprites,char buttonState[], sf::RenderWindow &window){
    
    if(buttonState[0] == 0){
        sprites.find("button")->second->setPosition(0, 500);
        window.draw(*sprites.find("button")->second);
    }
    else if(buttonState[0] == 2){
        sprites.find("buttonPressed")->second->setPosition(0, 500);
        window.draw(*sprites.find("buttonPressed")->second);
    }
    else{
        sprites.find("buttonHighlight")->second->setPosition(0, 500);
        window.draw(*sprites.find("buttonHighlight")->second);
    }
    
    if(buttonState[1] == 0){
        sprites.find("button")->second->setPosition(250, 500);
        window.draw(*sprites.find("button")->second);
    }
    else if(buttonState[1] == 2){
        sprites.find("buttonPressed")->second->setPosition(250, 500);
        window.draw(*sprites.find("buttonPressed")->second);
    }
    else{
        sprites.find("buttonHighlight")->second->setPosition(250, 500);
        window.draw(*sprites.find("buttonHighlight")->second);
    }
    
    if(buttonState[2] == 0){
        sprites.find("button")->second->setPosition(0, 600);
        window.draw(*sprites.find("button")->second);
    }
    else if(buttonState[2] == 2){
        sprites.find("buttonPressed")->second->setPosition(0, 600);
        window.draw(*sprites.find("buttonPressed")->second);
    }
    else{
        sprites.find("buttonHighlight")->second->setPosition(0, 600);
        window.draw(*sprites.find("buttonHighlight")->second);
    }
    
    if(buttonState[3] == 0){
        sprites.find("button")->second->setPosition(250, 600);
        window.draw(*sprites.find("button")->second);
    }
    else if(buttonState[3] == 2){
        sprites.find("buttonPressed")->second->setPosition(250, 600);
        window.draw(*sprites.find("buttonPressed")->second);
    }
    else{
        sprites.find("buttonHighlight")->second->setPosition(250, 600);
        window.draw(*sprites.find("buttonHighlight")->second);
    }
    
    if(buttonState[4] == 0){
        sprites.find("button")->second->setPosition(0, 700);
        window.draw(*sprites.find("button")->second);
    }
    else if(buttonState[4] == 2){
        sprites.find("buttonPressed")->second->setPosition(0, 700);
        window.draw(*sprites.find("buttonPressed")->second);
    }
    else{
        sprites.find("buttonHighlight")->second->setPosition(0, 700);
        window.draw(*sprites.find("buttonHighlight")->second);
    }
    
    if(buttonState[5] == 0){
        sprites.find("button")->second->setPosition(250, 700);
        window.draw(*sprites.find("button")->second);
    }
    else if(buttonState[5] == 2){
        sprites.find("buttonPressed")->second->setPosition(250, 700);
        window.draw(*sprites.find("buttonPressed")->second);
    }
    else{
        sprites.find("buttonHighlight")->second->setPosition(250, 700);
        window.draw(*sprites.find("buttonHighlight")->second);
    }
}

char buttonClick(sf::Vector2i &mousePos,char buttonState[]){
    if(mousePos.y >= 500 && mousePos.y <= 800 && mousePos.x >= 0 && mousePos.x <= 500){
        if(mousePos.y >= 700){
            if(mousePos.x >= 250){
                //if(buttonState[5] != 2)
                    buttonState[5] = 2;
                return 5;
            }
            else //if(buttonState[4] != 2)
                buttonState[4] = 2;
            return 4;
        }
        
        else if(mousePos.y >= 600){
            if(mousePos.x >= 250){
                //if(buttonState[3] != 2)
                    buttonState[3] = 2;
                return 4;
            }
            else //if(buttonState[2] != 2)
                buttonState[2] = 2;
            return 2;
        }
        
        else{
            if(mousePos.x >= 250){
                //if(buttonState[1] != 2)
                    buttonState[1] = 2;
                return 1;
            }
            else //if(buttonState[0] != 2)
                buttonState[0] = 2;
            return 0;
        }
    }
}

void gameTimer(unsigned int &health, unsigned int &age, unsigned int &hunger, unsigned int &happiness){
    chrono::seconds interval(1);
    while(true){
        health--;
        
        
        this_thread::sleep_for(interval);
    }
}

int main(int argc, char const** argv){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(500, 800), "Pet Project", sf::Style::Close);

    window.setVerticalSyncEnabled(true);
    
    Companions *companions = new Companions("Companions/list.txt");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("Assets/logo.png"))
        return EXIT_FAILURE;
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    map<string, sf::Sprite*> sprites = SpriteMaker(companions);
    
    char buttonState[6] = {0};
    
    char buttonPressed = -1;
    
    bool leftPressed = false;
    
    thread game(gameTimer, ref(companions->activeCompanion->health), ref(companions->activeCompanion->age), ref(companions->activeCompanion->hunger), ref(companions->activeCompanion->happiness));
    
    // Start the game loop
    while (window.isOpen())
    {
        
        // Clear screen
        window.clear(sf::Color(128, 128, 128, 255));
        
        for(int i = 0; i < 6; i++)
            if (buttonState[i] == 1)
                buttonState[i] = 0;
        
        // Process events
        sf::Event event;
        
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        buttonHover(buttonState, mousePos);
        
        while (window.pollEvent(event)){
            
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                window.close();
            }
            
            if(event.type == sf::Event::MouseButtonReleased){
                for(int i = 0; i < 6; i++)
                    buttonState[i] = 0;
                leftPressed = false;
            }
            
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && leftPressed == false){
                buttonPressed = buttonClick(mousePos, buttonState);
                leftPressed = true;
            }
        }
        
        switch(buttonPressed){
            case 0:
                sprites.find("comp")->second->setTexture(*companions->activeCompanion->textures.find("sad")->second);
                buttonPressed = -1;
                break;
            case 1:
                sprites.find("comp")->second->setTexture(*companions->activeCompanion->textures.find("neutral")->second);
                buttonPressed = -1;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
        
        window.draw(*sprites.find("comp")->second);
         
        sf::Font font;
        font.loadFromFile("Assets/sans.ttf");
        sf::Text text("sad", font);
        text.setCharacterSize(50);
        text.setStyle(sf::Text::Regular);
        text.setFillColor(sf::Color::Red);
        text.setPosition(0, 500);
        window.draw(text);
        
        text.setString("Happy");
        text.setCharacterSize(50);
        text.setStyle(sf::Text::Regular);
        text.setFillColor(sf::Color::Green);
        text.setPosition(250, 500);
        window.draw(text);
        
        text.setString(to_string(companions->activeCompanion->health));
        text.setCharacterSize(50);
        text.setStyle(sf::Text::Regular);
        text.setFillColor(sf::Color::Black);
        text.setPosition(0, 0);
        window.draw(text);
        
        
        drawButtons(sprites, buttonState, window);
        
        
        window.display();
    }
    return EXIT_SUCCESS;
}
