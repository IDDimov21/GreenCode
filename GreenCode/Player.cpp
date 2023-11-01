#include "Player.h"

Player::Player(sf::Vector2f startPosition, int initialHealth)
    : health(initialHealth) {
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setPosition(startPosition);
    shape.setFillColor(sf::Color::Green);
    velocity = sf::Vector2f(0.0f, 0.0f);
    speed = 10.0f;
}

void Player::handleInput() {
    velocity.x = 0.0f;
    velocity.y = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocity.x = -speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocity.x = speed;
    }
}

void Player::update() {
    shape.move(velocity);
}

int Player::getHealth() const {
    return health;
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

sf::RectangleShape& Player::getShape() {
    return shape;
}
