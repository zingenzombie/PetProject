#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "companion.hpp"
#include <thread>

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
    sf::Texture *compTx = new sf::Texture();
    compTx->loadFromImage(*companions->activeCompanion->textures.find("neutral")->second);
    sf::Sprite *comp = new sf::Sprite();
    comp->setTexture(*compTx);
    sprites.emplace("comp", comp);
    
    return sprites;
}

int main(int argc, char const** argv)
{
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
    
    char buttonHover[6] = {0};
    
    // Start the game loop
    while (window.isOpen())
    {
        
        // Clear screen
        window.clear(sf::Color(128, 128, 128, 255));
        
        for(int i = 0; i < 6; i++)
            if (buttonHover[i] == 1)
                buttonHover[i] = 0;
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            if(event.type == sf::Event::MouseButtonReleased)
                for(int i = 0; i < 6; i++)
                    buttonHover[i] = 0;
        }
        
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        //Button hovering
        if(mousePos.y >= 500 && mousePos.y <= 800 && mousePos.x >= 0 && mousePos.x <= 500){
            if(mousePos.y >= 700){
                if(mousePos.x >= 250){
                    if(buttonHover[5] != 2)
                        buttonHover[5] = 1;
                }
                else if(buttonHover[4] != 2)
                    buttonHover[4] = 1;
            }
            
            else if(mousePos.y >= 600){
                if(mousePos.x >= 250){
                    if(buttonHover[3] != 2)
                        buttonHover[3] = 1;
                }
                else if(buttonHover[2] != 2)
                    buttonHover[2] = 1;
            }
            
            else{
                if(mousePos.x >= 250){
                    if(buttonHover[1] != 2)
                        buttonHover[1] = 1;
                }
                else if(buttonHover[0] != 2)
                    buttonHover[0] = 1;
            }
        }
        
        if(event.type == sf::Event::MouseButtonPressed){
            cout << mousePos.x << " " << mousePos.y << endl;
            for(int i = 0; i < 6; i++)
                if(buttonHover[i] == 1){
                    buttonHover[i] = 2;
                    break;
                }
        }
        
        if(buttonHover[0] == 0){
            sprites.find("button")->second->setPosition(0, 500);
            window.draw(*sprites.find("button")->second);
        }
        else if(buttonHover[0] == 2){
            sprites.find("buttonPressed")->second->setPosition(0, 500);
            window.draw(*sprites.find("buttonPressed")->second);
        }
        else{
            sprites.find("buttonHighlight")->second->setPosition(0, 500);
            window.draw(*sprites.find("buttonHighlight")->second);
        }
        
        if(buttonHover[1] == 0){
            sprites.find("button")->second->setPosition(250, 500);
            window.draw(*sprites.find("button")->second);
        }
        else if(buttonHover[1] == 2){
            sprites.find("buttonPressed")->second->setPosition(250, 500);
            window.draw(*sprites.find("buttonPressed")->second);
        }
        else{
            sprites.find("buttonHighlight")->second->setPosition(250, 500);
            window.draw(*sprites.find("buttonHighlight")->second);
        }
        
        if(buttonHover[2] == 0){
            sprites.find("button")->second->setPosition(0, 600);
            window.draw(*sprites.find("button")->second);
        }
        else if(buttonHover[2] == 2){
            sprites.find("buttonPressed")->second->setPosition(0, 600);
            window.draw(*sprites.find("buttonPressed")->second);
        }
        else{
            sprites.find("buttonHighlight")->second->setPosition(0, 600);
            window.draw(*sprites.find("buttonHighlight")->second);
        }
        
        if(buttonHover[3] == 0){
            sprites.find("button")->second->setPosition(250, 600);
            window.draw(*sprites.find("button")->second);
        }
        else if(buttonHover[3] == 2){
            sprites.find("buttonPressed")->second->setPosition(250, 600);
            window.draw(*sprites.find("buttonPressed")->second);
        }
        else{
            sprites.find("buttonHighlight")->second->setPosition(250, 600);
            window.draw(*sprites.find("buttonHighlight")->second);
        }
        
        if(buttonHover[4] == 0){
            sprites.find("button")->second->setPosition(0, 700);
            window.draw(*sprites.find("button")->second);
        }
        else if(buttonHover[4] == 2){
            sprites.find("buttonPressed")->second->setPosition(0, 700);
            window.draw(*sprites.find("buttonPressed")->second);
        }
        else{
            sprites.find("buttonHighlight")->second->setPosition(0, 700);
            window.draw(*sprites.find("buttonHighlight")->second);
        }
        
        if(buttonHover[5] == 0){
            sprites.find("button")->second->setPosition(250, 700);
            window.draw(*sprites.find("button")->second);
        }
        else if(buttonHover[5] == 2){
            sprites.find("buttonPressed")->second->setPosition(250, 700);
            window.draw(*sprites.find("buttonPressed")->second);
        }
        else{
            sprites.find("buttonHighlight")->second->setPosition(250, 700);
            window.draw(*sprites.find("buttonHighlight")->second);
        }
        
        window.draw(*sprites.find("comp")->second);

        window.display();
    }
    
    return EXIT_SUCCESS;
}
