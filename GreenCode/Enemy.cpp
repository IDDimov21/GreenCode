#include "Enemy.h"

Enemy::Enemy(sf::Vector2f startPosition, int initialHealth)
    : health(initialHealth) {
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setPosition(startPosition);
    shape.setFillColor(sf::Color::Red);
}

void Enemy::update() {
    // Implement enemy behavior here (if any).
}

int Enemy::getHealth() const {
    return health;
}

void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

sf::RectangleShape& Enemy::getShape() {
    return shape;
}
