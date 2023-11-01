#include <SFML/Graphics.hpp>
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chemistry");

    Player player(sf::Vector2f(100.0f, 100.0f));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Player input handling
        player.handleInput();

        // Update player position
        player.update();

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}