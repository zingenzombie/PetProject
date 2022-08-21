#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "companion.hpp"

using namespace std;



int main(int argc, char const** argv)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(500, 800), "Pet Project", sf::Style::Close);

    window.setVerticalSyncEnabled(true);
    
    Companions *companions = new Companions("Companions/list.txt");
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("Assets/logo.png")) {
        return EXIT_FAILURE;
    }
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
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
        
        sf::Texture texture;
        texture.loadFromImage(*companions->activeCompanion->textures.find("test")->second);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        
        window.draw(sprite);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
