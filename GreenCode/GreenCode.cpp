#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Question.h"
#include <iostream>

using namespace sf;


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Battle Game");

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
    bool finishTextShown = false;

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
                            optionO.setPosition(100, 500); // Return to the original position.
                        }
                        if ((isOptionHInSlot1 && isOptionOInSlot2) || (isOptionHInSlot2 && isOptionOInSlot1)) {
                            // Both options were placed correctly, display finish text.
                            finishTextShown = true;
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
                            optionO.setPosition(100, 500); // Return to the original position.
                        }
                        if ((isOptionHInSlot1 && isOptionOInSlot2) || (isOptionHInSlot2 && isOptionOInSlot1)) {
                            // Both options were placed correctly, display finish text.
                            finishTextShown = true;
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

                if (finishTextShown) {
                    sf::Text finishText;
                    finishText.setFont(font);
                    finishText.setCharacterSize(40);
                    finishText.setFillColor(sf::Color::White);

                    if ((isOptionHInSlot1 && isOptionOInSlot2)) {
                        finishText.setString("Congratulations, you win!");
                    }
                    else {
                        finishText.setString("Options placed incorrectly. Restarting game...");
                        // Reset the game if options are placed incorrectly.
                        isOptionHInSlot1 = false;
                        isOptionHInSlot2 = false;
                        isOptionOInSlot1 = false;
                        isOptionOInSlot2 = false;
                        optionH.setPosition(100, 500);
                        optionO.setPosition(200, 500);
                        finishTextShown = false;
                    }

                    finishText.setPosition(250, 300);
                    window.draw(finishText);
                }
            }

            window.display();
        }
    }

    return 0;
}
