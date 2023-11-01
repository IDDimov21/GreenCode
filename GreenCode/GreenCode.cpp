#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Question.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Battle Game");

    Player player(sf::Vector2f(100.0f, 450.0f), 100);
    Enemy enemy(sf::Vector2f(600.0f, 450.0f), 100);

    // Create draggable elements for options.
    sf::RectangleShape optionH(sf::Vector2f(50, 50));
    optionH.setPosition(100, 500);
    optionH.setFillColor(sf::Color::Blue);

    sf::RectangleShape optionO(sf::Vector2f(50, 50));
    optionO.setPosition(200, 500);
    optionO.setFillColor(sf::Color::Red);

    // Create drop zones for answer slots.
    sf::RectangleShape answerSlot1(sf::Vector2f(100, 50));
    answerSlot1.setPosition(100, 100);
    answerSlot1.setFillColor(sf::Color::Transparent);
    answerSlot1.setOutlineThickness(2);
    answerSlot1.setOutlineColor(sf::Color::White);

    sf::RectangleShape answerSlot2(sf::Vector2f(100, 50));
    answerSlot2.setPosition(200, 100);
    answerSlot2.setFillColor(sf::Color::Transparent);
    answerSlot2.setOutlineThickness(2);
    answerSlot2.setOutlineColor(sf::Color::White);

    sf::Font font;
    font.loadFromFile("arial.ttf"); // Load a font for displaying text.

    // Create a vector of questions.
    std::vector<Question> questions = {
        Question("How to make water?", "H2O"),
        // Add more questions here.
    };

    int currentQuestionIndex = 0; // Index of the current question.

    sf::Text questionText;
    questionText.setFont(font);
    questionText.setCharacterSize(20);
    questionText.setFillColor(sf::Color::White);

    bool questionAnswered = false;

    bool battleStarted = false;

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
                if (!questionAnswered) {
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                        // Check for mouse click on draggable elements.
                        if (optionH.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            // Logic for dragging option H.
                        }
                        else if (optionO.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            // Logic for dragging option O.
                        }
                    }
                    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                        // Check for mouse release on answer slots.
                        if (answerSlot1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            // Logic for dropping option H into slot 1.
                            // Check if the answer is correct and update the game accordingly.
                        }
                        else if (answerSlot2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            // Logic for dropping option O into slot 2.
                            // Check if the answer is correct and update the game accordingly.
                        }
                    }
                }
                else {
                    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
                        if (currentQuestionIndex < questions.size() - 1) {
                            currentQuestionIndex++;
                            questionAnswered = false;
                            // Reset the draggable elements to their original positions.
                            optionH.setPosition(100, 500);
                            optionO.setPosition(200, 500);
                        }
                        else {
                            window.close();
                        }
                    }
                }
            }
        }

        window.clear();

        if (!battleStarted) {
            window.draw(player.getShape());
            window.draw(enemy.getShape());
        }
        else {
            window.draw(questionText);
            if (!questionAnswered) {
                window.draw(optionH);
                window.draw(optionO);
                window.draw(answerSlot1);
                window.draw(answerSlot2);
            }
        }

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
