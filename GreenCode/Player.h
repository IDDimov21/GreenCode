#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
public:
    Player(sf::Vector2f startPosition, int initialHealth);
    void handleInput();
    void update();
    int getHealth() const;
    void takeDamage(int damage);
    sf::RectangleShape& getShape();
private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    float speed;
    int health;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // PLAYER_H
