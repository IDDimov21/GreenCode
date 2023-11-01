#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(sf::Vector2f startPosition, int initialHealth);
    void update();
    int getHealth() const;
    void takeDamage(int damage);

    sf::RectangleShape& getShape();

private:
    sf::RectangleShape shape;
    int health;
};

#endif
