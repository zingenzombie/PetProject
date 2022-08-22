#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "companion.hpp"

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
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(window.hasFocus()){
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                
                
            }
            
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        
        sprites.find("button")->second->setPosition(0, 500);
        window.draw(*sprites.find("button")->second);
        sprites.find("button")->second->setPosition(250, 500);
        window.draw(*sprites.find("button")->second);
        sprites.find("button")->second->setPosition(0, 600);
        window.draw(*sprites.find("button")->second);
        sprites.find("button")->second->setPosition(250, 600);
        window.draw(*sprites.find("button")->second);
        sprites.find("button")->second->setPosition(0, 700);
        window.draw(*sprites.find("button")->second);
        sprites.find("button")->second->setPosition(250, 700);
        window.draw(*sprites.find("button")->second);
        
        window.draw(*sprites.find("comp")->second);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
