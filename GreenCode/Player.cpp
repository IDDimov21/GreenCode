#include "Player.h"

Player::Player(sf::Vector2f startPosition) {
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setPosition(startPosition);
    shape.setFillColor(sf::Color::Green);
    velocity = sf::Vector2f(0.0f, 0.0f);
    speed = 0.075f;
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velocity.y = -speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        velocity.y = speed;
    }
}

void Player::update() {
    shape.move(velocity);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}