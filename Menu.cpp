#include "Menu.hpp"
 
int main() { 
    sf::RenderWindow window(sf::VideoMode(1280, 900), "SFML Menu"); 
 
    sf::Font font; 
    if (!font.loadFromFile("arial.ttf")) { 
        std::cerr << "Failed to load font" << std::endl; 
        return -1; 
    } 
 
    sf::Texture bgTexture; 
    if (!bgTexture.loadFromFile("bg.jpeg")) { 
        std::cerr << "Failed to load background texture" << std::endl; 
        return -1; 
    } 
 
    Menu menu(bgTexture); 
 
    menu.addItem(std::make_unique<TextMenuItem>("Start Game", font, 50, sf::Vector2f(550, 280))); 
    menu.addItem(std::make_unique<TextMenuItem>("Options", font, 50, sf::Vector2f(590, 350)));
    menu.addItem(std::make_unique<TextMenuItem>("Credits", font, 50, sf::Vector2f(590, 430))); 
    menu.addItem(std::make_unique<TextMenuItem>("Exit", font, 50, sf::Vector2f(620, 510))); 
 
    while (window.isOpen()) { 
        sf::Event event; 
        while (window.pollEvent(event)) { 
            if (event.type == sf::Event::Closed) { 
                window.close(); 
            } 
 
            menu.handleInput(event, window); 
        } 
 
        window.clear(); 
        menu.draw(window); 
        window.display(); 
    } 
 
    return 0; 
}