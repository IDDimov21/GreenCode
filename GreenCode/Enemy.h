#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy : public sf::Drawable {
public:
    Enemy(sf::Vector2f startPosition, int initialHealth);
    void update();
    int getHealth() const;
    void takeDamage(int damage);
    sf::RectangleShape& getShape();
private:
    sf::RectangleShape shape;
    int health;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // ENEMY_H
