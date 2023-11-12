#include "raylib.h" //raylib setup
#include <iostream>
#include <string>
#include "gameStructures.h"
using namespace std;

void MoveAnimation(float& timer, int& frame, int maxFrames, float frameWidth, Texture2D Run, float& x1, float& y1) {
    timer += GetFrameTime();

    // Control the frame switch based on timer
    if (timer >= 0.135f) {
        timer = 0.0f;
        frame += 1;
    }

    frame = frame % maxFrames;  // Ensure the frame stays within the range

    // Draw the specific frame from the spritesheet
    DrawTextureRec(Run, Rectangle{ frameWidth * frame, 0, frameWidth, (float)Run.height }, Vector2{ x1, y1 }, RAYWHITE);
}

void MoveAnimationBackwards(float& timer, int& frame, int maxFrames, float frameWidth, Texture2D Run, float& x1, float& y1) {
    timer += GetFrameTime();

    // Control the frame switch based on timer
    if (timer >= 0.135f) {
        timer = 0.0f;
        frame += 1;
    }

    frame = frame % maxFrames;  // Ensure the frame stays within the range

    // Draw the specific frame from the spritesheet
    DrawTextureRec(Run, Rectangle{ frameWidth * frame, 0, frameWidth, (float)Run.height }, Vector2{ x1, y1 }, RAYWHITE);
}

int main() {

    Player player;
    Enemy enemy;
    Option option1, option2;

    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Basic Game");

    player.Health = 100;
    player.x = screenWidth / 5;
    player.y = screenHeight / 2;

    enemy.EnemyHealth = 100;
    enemy.x = 700;
    enemy.y = screenHeight / 2;
    float movespeed = 5;

    int counter = 0;
    int resetcounter = 0;

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
    bool check = false;

    Texture2D background = LoadTexture("resources/background.png");
    Texture2D character = LoadTexture("resources/CharaWalk.png");
    Texture2D characterLeft = LoadTexture("resources/CharaWalkBack.png");

    float frameWidthPlayer = (float)(character.width / 6);
    int maxFramesPlayer = (int)(character.width / (int)frameWidthPlayer);
    float timer = 0.0f;
    int framePlayer = 0;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        

        if (player.x <= 1.0f)
            player.x = 1.0f;

        if (player.x == enemy.x - 70.0f) {
            collision = true;
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

        if (resetcounter == 0) {
            Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot1);
            Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot2);
        }
        else if (resetcounter == 1) {
            Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot2);
            Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot1);
        }
        else if (resetcounter == 2) {
            Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot2);
            Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot1);
        }
        cout << maxFramesPlayer << " " << frameWidthPlayer << " " << framePlayer << endl;

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
            if (counter == 0) {
                enemy.EnemyHealth -= 40;
                counter++;
            }
            else {
                enemy.EnemyHealth -= 30;
            }
            dmgenemy = true;
            isSnapped = false;
            turncheck = false;
            resetcounter += 1;  
        }


            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(background, screenWidth/2 - 600, screenHeight/2-390, WHITE);
            

            if (!deleteEnemy1) {
                DrawRectangle(player.x, player.y, 70, 70, DARKBLUE);
                DrawRectangle(enemy.x, enemy.y, 70, 70, RED);
            }
            if (collision) {
                if (!gamestop) {
                    DrawText("PLAYER HEALTH: ", 50, 55, 28, WHITE);
                    DrawText(to_string(player.Health).c_str(), 300, 55, 30, WHITE);
                    DrawText("ENEMY HEALTH: ", 875, 55, 28, WHITE);
                    DrawText(to_string(enemy.EnemyHealth).c_str(), 1110, 55, 30, WHITE);
                    if (resetcounter == 0) {
                        DrawText("Connect the elements of: Water", 395, 135, 28, WHITE);
                    }
                    else if (resetcounter == 1) {
                        DrawText("Connect the elements of: Hydrochloric Acid", 50, 185, 28, WHITE);
                    }
                    else if (resetcounter == 2) {
                        DrawText("Connect the elements of: Sodium Chloride", 50, 185, 28, WHITE);
                    }

                    DrawRectangleLines(475, 215, 100, 75, WHITE);
                    DrawRectangleLines(650, 215, 100, 75, WHITE);

                    DrawRectangleRec(Option1, YELLOW);
                    DrawRectangleRec(Option2, GREEN);

                }
                if (enemy.EnemyHealth <= 0) {
                    gamestop = true;
                    deleteEnemy1 = true;
                    collision = false;
                    DrawText("CONGRATULATIONS YOU PASSED THE LEVEL!! ", 200, 350, 32, WHITE);
                }
                if (player.Health <= 0) {
                    gamestop = true;
                    deleteEnemy1 = true;
                    collision = false;
                    DrawText("Nice try :( !! Good luck next time!", 300, 350, 32, WHITE);
                }
            }
            if (!collision) {
                if (IsKeyDown('D')) {
                    player.x += movespeed;
                    MoveAnimation(timer, framePlayer, maxFramesPlayer, frameWidthPlayer, character, player.x, player.y);
                }
                else if (IsKeyDown('A')) {
                    player.x -= movespeed;
                    MoveAnimationBackwards(timer, framePlayer, maxFramesPlayer, frameWidthPlayer, characterLeft, player.x, player.y);
                }
                else {
                    // Draw the default frame if no movement keys are pressed
                    DrawTextureRec(character, Rectangle{ 0, 0, frameWidthPlayer, (float)character.height }, Vector2{ player.x, player.y }, RAYWHITE);
                }
            }

            EndDrawing();
            //----------------------------------------------------------------------------------
            // Check if the display duration has passed and exit the loop

        }

        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------
        UnloadTexture(background);
        return 0;
    }