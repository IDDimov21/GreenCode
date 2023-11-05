#include "raylib.h" //raylib setup
#include <iostream>
#include <string>
using namespace std;

//player structure
struct Player {
    float x;
    float y;
    int Health;
}player;

//enemies structure
struct Enemy {
    float x;
    float y;
    int EnemyHealth;
    bool isAlive;
}enemy;

struct Option1 {
    float x;
    float y;
}option1;

//enemies structure
struct Option2 {
    float x;
    float y;
}option2;

void DragNDrop(bool& collision, bool& isDragging, bool& isSnapped, bool& check1, Rectangle& Option, Rectangle& OptionSlot1, Rectangle& OptionSlot2) {

    if (collision) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), Option)) {
            isDragging = true;
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            isDragging = false;
            if (CheckCollisionRecs(Option, OptionSlot1)) {
                Option.x = OptionSlot1.x + 14;
                Option.y = OptionSlot1.y + 2;
                isSnapped = true;
                check1 = true;
            }
            if (CheckCollisionRecs(Option, OptionSlot2)) {
                Option.x = OptionSlot2.x + 14;
                Option.y = OptionSlot2.y + 2;
                isSnapped = true;
                check1 = true;
            }
        }
        if (isDragging) {
            Option.x = GetMouseX() - Option.width / 2;
            Option.y = GetMouseY() - Option.height / 2;
            isSnapped = false;
        }
    }
}

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 800;

    player.Health = 100;
    player.x = screenWidth / 5;
    player.y = screenHeight / 2;

    enemy.EnemyHealth = 100;
    enemy.x = 700;
    enemy.y = screenHeight / 2;
    float movespeed = 5;

    option1.x = 300;
    option1.y = 600;
    option2.x = 380;
    option2.y = 600;

    Rectangle playerRec = { player.x, player.y, 75, 75 };
    Rectangle enemyRec = { enemy.x, player.y, 75, 75 };

    Rectangle OptionSlot1 = { 525, 100, 100, 95 };
    Rectangle OptionSlot2 = { 650, 100, 100, 95 };

    Rectangle Option1 = { option1.x, option1.y, 70, 70 };
    Rectangle Option2 = { option2.x, option2.y, 70, 70 };

    bool collision = false;
    bool isDragging = false;
    bool isSnapped = false;
    bool turncheck = false;
    bool flag = false;
    bool Option1inCorrectSlot = false;
    bool Option2inCorrectSlot = false;

    InitWindow(screenWidth, screenHeight, "Basic Game");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (player.x <= 1.0f)
            player.x = 1.0f;

        if (player.x == enemy.x - 70.0f) {
            collision = true;
        }
        if (!collision) {
            if (IsKeyDown('D')) {
                player.x += movespeed;
            }
            if (IsKeyDown('A')) {
                player.x -= movespeed;
            }
        }
        if (!turncheck)
            DragNDrop(collision, isDragging, isSnapped, turncheck, Option1, OptionSlot1, OptionSlot2);
        if (turncheck)
            DragNDrop(collision, isDragging, isSnapped, turncheck, Option2, OptionSlot1, OptionSlot2);

        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot1);
        Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot2);


        if (Option1inCorrectSlot && Option2inCorrectSlot && !flag && isSnapped) {
            enemy.EnemyHealth -= 50;
            flag = true;
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(player.x, player.y, 70, 70, DARKBLUE);
        DrawRectangle(enemy.x, enemy.y, 70, 70, RED);
        if (collision) {
            DrawText("PLAYER HEALTH: ", 50, 100, 28, WHITE);
            DrawText(to_string(player.Health).c_str(), 300, 100, 30, WHITE);
            DrawText("ENEMY HEALTH: ", 50, 150, 28, WHITE);
            DrawText(to_string(enemy.EnemyHealth).c_str(), 290, 150, 30, WHITE);

            DrawRectangleLines(525, 100, 100, 75, WHITE);
            DrawRectangleLines(650, 100, 100, 75, WHITE);

            DrawRectangleRec(Option1, YELLOW);
            DrawRectangleRec(Option2, GREEN);


        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}