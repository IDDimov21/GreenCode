#include "gameLogic.h"
#include "raylib.h" //raylib setup
#include <iostream>
#include <string>

void CheckIfWinOrLose(bool& gamestop, bool& deleteEnemy1, bool& collision, int& EnemyHealth, int& Health) {
    if (EnemyHealth <= 0) {
        gamestop = true;
        deleteEnemy1 = true;
        collision = false;
        DrawText("CONGRATULATIONS YOU PASSED THE LEVEL!! ", 200, 350, 32, WHITE);
    }
    if (Health <= 0) {
        gamestop = true;
        deleteEnemy1 = true;
        collision = false;
        DrawText("Nice try :( !! Good luck next time!", 300, 350, 32, WHITE);
    }
}

void DrawHealth(int Health, int EnemyHealth) {
    DrawText("PLAYER HEALTH: ", 50, 55, 28, WHITE);
    DrawText(std::to_string(Health).c_str(), 300, 55, 30, WHITE);
    DrawText("ENEMY HEALTH: ", 875, 55, 28, WHITE);
    DrawText(std::to_string(EnemyHealth).c_str(), 1110, 55, 30, WHITE);
}