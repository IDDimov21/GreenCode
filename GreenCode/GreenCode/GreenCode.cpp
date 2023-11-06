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

    float* original1X = &Option1.x, * original2X = &Option2.x, * original1Y = &Option1.y, * original2Y = &Option2.y;

    int timer = 0; // Initialize the timer at 0
    int startTime = GetTime(); // Get the current time in seconds
    int currentTime;
    
    bool collision = false;
    bool isDragging = false;
    bool isSnapped = false;
    bool turncheck = false;
    bool flag = false;
    bool Option1inCorrectSlot = false;
    bool Option2inCorrectSlot = false;
    bool gamestop = false;
    bool deleteEnemy1 = false;
    bool isinslot1 = false;
    bool isinslot2 = false;
    bool dmgplayer = false;
    bool dmgenemy = false;

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

        isinslot1 = CheckCollisionRecs(Option1, OptionSlot1);
        if (!isinslot1) {
            isinslot1 = CheckCollisionRecs(Option2, OptionSlot1);
        }
        isinslot2 = CheckCollisionRecs(Option1, OptionSlot2);
        if (!isinslot2) {
            isinslot2 = CheckCollisionRecs(Option2, OptionSlot2);
        }

        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot1);
        Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot2);

        cout << isinslot1 << " " << isinslot2 << " " << Option1inCorrectSlot << " " << Option2inCorrectSlot << endl;

        if ((isinslot1 && !Option1inCorrectSlot) && (isinslot2 && !Option2inCorrectSlot) && isSnapped) {
                *original1X = 300;
                *original1Y = 600;
                *original2X = 380;
                *original2Y = 600;
                player.Health -= 25;
                dmgplayer = true;
                isSnapped = false;
                turncheck = false;
            }

        if (Option1inCorrectSlot && Option2inCorrectSlot && isSnapped) {
            *original1X = 300;
            *original1Y = 600;
            *original2X = 380;
            *original2Y = 600;
            enemy.EnemyHealth -= 25;
            dmgenemy = true;
            isSnapped = false;
            turncheck = false;
        }



            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(BLACK);
            
            if (!deleteEnemy1) {
                DrawRectangle(player.x, player.y, 70, 70, DARKBLUE);
                DrawRectangle(enemy.x, enemy.y, 70, 70, RED);
            }
            if (collision) {
                if (!gamestop) {
                    
                    DrawText("PLAYER HEALTH: ", 50, 70, 28, WHITE);
                    DrawText(to_string(player.Health).c_str(), 300, 70, 30, WHITE);
                    DrawText("ENEMY HEALTH: ", 50, 120, 28, WHITE);
                    DrawText(to_string(enemy.EnemyHealth).c_str(), 290, 115, 30, WHITE);
                    DrawText("Connect the elements of: Water", 50, 165, 28, WHITE);

                    DrawRectangleLines(525, 100, 100, 75, WHITE);
                    DrawRectangleLines(650, 100, 100, 75, WHITE);

                    DrawRectangleRec(Option1, YELLOW);
                    DrawRectangleRec(Option2, GREEN);

 /*                   if (dmgplayer) {
                        dmgplayer = false;

                        DrawText("-25", 100, 70, 28, RED);
                    }
                    if (dmgenemy) {
                        dmgenemy = false;
                        currentTime = GetTime();
                        timer = currentTime - startTime;
                        if (timer <= 2) {
                            DrawText("-25", 100, 120, 28, RED);
                        }
                    }*/
                }
                if (enemy.EnemyHealth <= 0 || player.Health <= 0) {
                    gamestop = true;
                    deleteEnemy1 = true;
                    collision = false;
                    DrawText("CONGRATULATIONS YOU PASSED THE LEVEL!! ", 110, 350, 32, WHITE);
                }
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