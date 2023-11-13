#include "gameLogic.h"
#include "raylib.h" //raylib setup
#include <iostream>
#include <string>

void CheckIfWinOrLose(bool& gamestop, bool& deleteEnemy1, bool& collision, int& EnemyHealth, int& Health) {
    if (EnemyHealth <= 0) {
        gamestop = true;
        deleteEnemy1 = true;
        collision = false;
        DrawRectangle(200, 180, 750, 60, BLACK);
        DrawText("CONGRATULATIONS YOU PASSED THE LEVEL!! ", 210, 200, 30, GREEN);
    }
    if (Health <= 0) {
        gamestop = true;
        deleteEnemy1 = true;
        collision = false;
        DrawRectangle(275, 180, 650, 60, BLACK);
        DrawText("Nice try :( !! Good luck next time!", 325, 195, 32, GREEN);
    }
}

void DrawHealth(int Health, int EnemyHealth) {
    DrawText("PLAYER HEALTH: ", 50, 55, 28, WHITE);
    DrawText(std::to_string(Health).c_str(), 300, 55, 30, WHITE);
    DrawText("ENEMY HEALTH: ", 875, 55, 28, WHITE);
    DrawText(std::to_string(EnemyHealth).c_str(), 1110, 55, 30, WHITE);
}