#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Question.h"
#include <iostream>

using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Battle Game");

    Player player(sf::Vector2f(100.0f, 450.0f), 100);
    Enemy enemy(sf::Vector2f(600.0f, 450.0f), 100);

    // Create draggable elements for options.
    sf::RectangleShape optionH(sf::Vector2f(50, 50));
    optionH.setPosition(100, 500);
    optionH.setFillColor(sf::Color::Blue);
    bool isDraggingOptionH = false;

    sf::RectangleShape optionO(sf::Vector2f(50, 50));
    optionO.setPosition(200, 500);
    optionO.setFillColor(sf::Color::Red);
    bool isDraggingOptionO = false;

    // Create drop zones for answer slots.
    sf::RectangleShape answerSlot1(sf::Vector2f(100, 50));
    answerSlot1.setPosition(100, 100);
    answerSlot1.setFillColor(sf::Color::Transparent);
    answerSlot1.setOutlineThickness(2);
    answerSlot1.setOutlineColor(sf::Color::White);
    bool isOptionHInSlot1 = false;
    bool isOptionOInSlot1 = false;

    sf::RectangleShape answerSlot2(sf::Vector2f(100, 50));
    answerSlot2.setPosition(200, 100);
    answerSlot2.setFillColor(sf::Color::Transparent);
    answerSlot2.setOutlineThickness(2);
    answerSlot2.setOutlineColor(sf::Color::White);
    bool isOptionHInSlot2 = false;
    bool isOptionOInSlot2 = false;

    sf::Font font;
    font.loadFromFile("PixelEmulator-xq08.ttf"); // Load a font for displaying text.

    int currentQuestionIndex = 0; // Index of the current question.

    bool battleStarted = false;
    bool returnBoxesToOriginalPlaces = false;
    bool allBoxesFilled = false; // Flag to track if all boxes are filled

    // Health variables for the player and enemy
    int playerHealth = 100;
    int enemyHealth = 100;

    // Create a question
    Question question("What is 2 + 2?", "4");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!battleStarted) {
                if (player.getShape().getGlobalBounds().intersects(enemy.getShape().getGlobalBounds())) {
                    battleStarted = true;
                }
                else {
                    player.handleInput();
                    player.update();
                }
            }

            if (battleStarted) {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                    if (!isOptionHInSlot1 && optionH.getGlobalBounds().contains(mousePosition)) {
                        isDraggingOptionH = true;
                    }
                    if (!isOptionOInSlot1 && optionO.getGlobalBounds().contains(mousePosition)) {
                        isDraggingOptionO = true;
                    }
                }
                else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                    if (isDraggingOptionH) {
                        isDraggingOptionH = false;
                        sf::Vector2f mousePosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        if (answerSlot1.getGlobalBounds().contains(mousePosition)) {
                            isOptionHInSlot1 = true;
                            optionH.setPosition(answerSlot1.getPosition().x, answerSlot1.getPosition().y); // Snap to slot.
                        }
                        else if (answerSlot2.getGlobalBounds().contains(mousePosition)) {
                            isOptionHInSlot2 = true;
                            optionH.setPosition(answerSlot2.getPosition().x, answerSlot2.getPosition().y); // Snap to slot.
                        }
                        else {
                            optionH.setPosition(100, 500); // Return to the original position.
                            optionO.setPosition(200, 500); // Return to the original position.
                            returnBoxesToOriginalPlaces = true;
                            allBoxesFilled = false;
                        }
                        if (isOptionHInSlot1 && isOptionOInSlot2) {
                            allBoxesFilled = true;
                        }
                    }
                    if (isDraggingOptionO) {
                        isDraggingOptionO = false;
                        sf::Vector2f mousePosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        if (answerSlot1.getGlobalBounds().contains(mousePosition)) {
                            isOptionOInSlot1 = true;
                            optionO.setPosition(answerSlot1.getPosition().x, answerSlot1.getPosition().y); // Snap to slot.
                        }
                        else if (answerSlot2.getGlobalBounds().contains(mousePosition)) {
                            isOptionOInSlot2 = true;
                            optionO.setPosition(answerSlot2.getPosition().x, answerSlot2.getPosition().y); // Snap to slot.
                        }
                        else {
                            optionH.setPosition(100, 500); // Return to the original position.
                            optionO.setPosition(200, 500); // Return to the original position.
                            returnBoxesToOriginalPlaces = true;
                            allBoxesFilled = false;
                        }
                        if (isOptionHInSlot1 && isOptionOInSlot2) {
                            allBoxesFilled = true;
                        }
                    }
                }
                else if (event.type == sf::Event::MouseMoved) {
                    if (isDraggingOptionH) {
                        optionH.setPosition(static_cast<float>(event.mouseMove.x) - 25, static_cast<float>(event.mouseMove.y) - 25);
                    }
                    if (isDraggingOptionO) {
                        optionO.setPosition(static_cast<float>(event.mouseMove.x) - 25, static_cast<float>(event.mouseMove.y) - 25);
                    }
                }
            }

            window.clear();

            if (!battleStarted) {
                window.draw(player.getShape());
                window.draw(enemy.getShape());
            }
            else {
                window.draw(player.getShape());
                window.draw(enemy.getShape());
                window.draw(optionH);
                window.draw(optionO);
                window.draw(answerSlot1);
                window.draw(answerSlot2);

                if (returnBoxesToOriginalPlaces) {
                    // Reset the game if options are placed incorrectly.
                    isOptionHInSlot1 = false;
                    isOptionHInSlot2 = false;
                    isOptionOInSlot1 = false;
                    isOptionOInSlot2 = false;
                    optionH.setPosition(100, 500);
                    optionO.setPosition(200, 500);
                    returnBoxesToOriginalPlaces = false;
                }
            

                // Check the positions after all boxes are filled
                if (allBoxesFilled) {
                    if (isOptionHInSlot1 && isOptionOInSlot2) {
                        // Blue option on the left and red option on the right, take 10 from the enemy.
                        enemyHealth -= 10;
                    }
                    else {
                        // Blue option on the right and red option on the left, take 10 from the player.
                        playerHealth -= 10;
                    }
                    returnBoxesToOriginalPlaces = true;
                    allBoxesFilled = false;
                }
            }

            // Display player and enemy health
            sf::Text playerHealthText;
            playerHealthText.setFont(font);
            playerHealthText.setCharacterSize(20);
            playerHealthText.setFillColor(sf::Color::White);
            playerHealthText.setPosition(50, 50);
            playerHealthText.setString("Player Health: " + std::to_string(playerHealth));
            window.draw(playerHealthText);

            sf::Text enemyHealthText;
            enemyHealthText.setFont(font);
            enemyHealthText.setCharacterSize(20);
            enemyHealthText.setFillColor(sf::Color::White);
            enemyHealthText.setPosition(600, 50);
            enemyHealthText.setString("Enemy Health: " + std::to_string(enemyHealth));
            window.draw(enemyHealthText);

            // Check if the battle is over
            if (playerHealth <= 0) {
                // Player loses
                sf::Text gameOverText;
                gameOverText.setFont(font);
                gameOverText.setCharacterSize(40);
                gameOverText.setFillColor(sf::Color::White);
                gameOverText.setString("Game Over! You lose.");
                gameOverText.setPosition(250, 300);
                window.draw(gameOverText);
            }
            else if (enemyHealth <= 0) {
                // Player wins
                sf::Text winText;
                winText.setFont(font);
                winText.setCharacterSize(40);
                winText.setFillColor(sf::Color::White);
                winText.setString("Congratulations, you win!");
                winText.setPosition(250, 300);
                window.draw(winText);
            }

            window.display();
        }
    }
    return 0;
}
    

