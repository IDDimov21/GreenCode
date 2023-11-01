#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

enum class GameState { Exploration, Battle };

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    Player player(sf::Vector2f(100.0f, 450.0f), 100);
    Enemy enemy(sf::Vector2f(600.0f, 450.0f), 100);

    GameState gameState = GameState::Exploration;

    sf::Font font;
    font.loadFromFile("PixelEmulator-xq08.ttf"); // Load a font for displaying text.

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle input and updates based on the game state.
        if (gameState == GameState::Exploration) {
            player.handleInput();
            player.update();
            enemy.update();

            // Check for collision between player and enemy.
            if (player.getShape().getGlobalBounds().intersects(enemy.getShape().getGlobalBounds())) {
                gameState = GameState::Battle;
            }
        }

        window.clear();

        // Render game elements based on the game state.
        if (gameState == GameState::Exploration) {
            window.draw(player);
            window.draw(enemy);
        }
        else if (gameState == GameState::Battle) {
            // Render battle elements here.

            // For now, let's draw a message to indicate battle state.
            sf::Text battleMessage;
            battleMessage.setFont(font);
            battleMessage.setCharacterSize(30);
            battleMessage.setFillColor(sf::Color::White);
            battleMessage.setString("Battle");
            battleMessage.setPosition(150.0f, 150.0f);
            window.draw(battleMessage);
            // You can implement your battle mechanics here.
        }

        // Display player and enemy health.
        sf::Text playerHealthText;
        playerHealthText.setFont(font);
        playerHealthText.setCharacterSize(20);
        playerHealthText.setFillColor(sf::Color::White);
        playerHealthText.setString("Player Health: " + std::to_string(player.getHealth()));
        playerHealthText.setPosition(10.0f, 10.0f);

        sf::Text enemyHealthText;
        enemyHealthText.setFont(font);
        enemyHealthText.setCharacterSize(20);
        enemyHealthText.setFillColor(sf::Color::White);
        enemyHealthText.setString("Enemy Health: " + std::to_string(enemy.getHealth()));
        enemyHealthText.setPosition(10.0f, 40.0f);

        window.draw(playerHealthText);
        window.draw(enemyHealthText);


        window.display();
    }

    return 0;
}
