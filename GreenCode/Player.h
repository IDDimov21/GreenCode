// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2f startPosition);

    void handleInput();
    void update();
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    float speed;

};

#endif // PLAYER_H
