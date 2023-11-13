#include "Normal.h"
#include "dragAndDrop.h"
#include "moveFunctions.h"
#include "gameLogic.h"
using namespace std;


int main() {

    Player player;
    Enemy enemy;
    Option option1, option2;

    Image icon = LoadImage("resources/Icon.png");

    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "GreenCode Game");
    SetWindowIcon(icon);

    player.Health = 100;
    player.x = screenWidth / 5;
    player.y = 535;

    enemy.EnemyHealth = 100;
    enemy.x = 850;
    enemy.y = 515;
    float movespeed = 5;

    int counter = 0;
    int resetcounter = 0;

    option1.x = 300;
    option1.y = 600;
    option2.x = 380;
    option2.y = 600;

    Rectangle playerRec = { player.x, player.y, 75, 75 };
    Rectangle enemyRec = { enemy.x, player.y, 75, 75 };

    Rectangle OptionSlot1 = { 475, 215, 100, 75 };
    Rectangle OptionSlot2 = { 650, 215, 100, 75 };

    Rectangle Option1 = { option1.x, option1.y, 70, 70 };
    Rectangle Option2 = { option2.x, option2.y, 70, 70 };

    float* original1X = &Option1.x, * original2X = &Option2.x, * original1Y = &Option1.y, * original2Y = &Option2.y;

    Texture2D background = LoadTexture("resources/background.png");
    Texture2D textbg = LoadTexture("resources/text1.png");
    Texture2D textbg2 = LoadTexture("resources/text2.png");
    Texture2D character = LoadTexture("resources/CharaWalk.png");
    Texture2D characterLeft = LoadTexture("resources/CharaWalkBack.png");
    Texture2D Enemy = LoadTexture("resources/enemyPotion.png");
    Texture2D H = LoadTexture("resources/H.png");
    Texture2D O = LoadTexture("resources/O.png");
    Texture2D Na = LoadTexture("resources/Na.png");
    Texture2D Cl = LoadTexture("resources/Cl.png");

    float frameWidthPlayer = (float)(character.width / 6);
    int maxFramesPlayer = (int)(character.width / (int)frameWidthPlayer);
    int framePlayer = 0;
    float timer = 0.0f;
    float frameWidthEnemy = (float)(Enemy.width / 4);
    int maxFramesEnemy = (int)(Enemy.width / (int)frameWidthPlayer);
    int frameEnemy = 0;
    float timer2 = 0.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        barrier(player.x);

        if (player.x == enemy.x - 100.0f) {
            collision = true;
        }
            DragNDrop(collision, isDragging1, isSnapped1, turncheck1, Option1, OptionSlot1, OptionSlot2);
            DragNDrop(collision, isDragging2, isSnapped2, turncheck2, Option2, OptionSlot1, OptionSlot2);


        CheckIfAnswerIsInTheSlot(isinslot1, isinslot2, Option1, Option2, OptionSlot1, OptionSlot2);

        NewObjective(resetcounter, Option1inCorrectSlot, Option2inCorrectSlot, Option1, Option2, OptionSlot1, OptionSlot2);

        DragNDropCheckAndDamage(isinslot1, isinslot2, Option1inCorrectSlot, Option2inCorrectSlot, isSnapped, turncheck, dmgplayer, dmgenemy, original1X, original1Y, original2X, original2Y, player.Health, enemy.EnemyHealth, counter, resetcounter);


            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();
            ClearBackground(WHITE);
            DrawTexture(background, screenWidth/2 - 600, screenHeight/2-390, WHITE);
            if (collision) {
                if (!gamestop) {
                    DrawTextureRec(character, Rectangle{ 0, 0, frameWidthPlayer, (float)character.height }, Vector2{ player.x, player.y }, RAYWHITE);
                    DrawTexture(textbg, 25, 40, WHITE);
                    DrawTexture(textbg, 840, 40, WHITE);
                    DrawHealth(player.Health, enemy.EnemyHealth);

                    if (resetcounter == 0) {
                        DrawTexture(textbg2, 380, 115, WHITE);
                        DrawRectangle(475, 215, 100, 75, WHITE);
                        DrawRectangle(650, 215, 100, 75, WHITE);
                        DrawTexture(H, Option1.x, Option1.y, WHITE);
                        DrawTexture(O, Option2.x, Option2.y, WHITE);
                        DrawText("Connect the elements of: Water", 395, 135, 28, WHITE);
                    }
                    else if (resetcounter == 1) {
                        DrawTexture(textbg2, 380, 115, WHITE);
                        DrawRectangle(475, 215, 100, 75, WHITE);
                        DrawRectangle(650, 215, 100, 75, WHITE);
                        DrawTexture(Cl, Option1.x, Option1.y, WHITE);
                        DrawTexture(Na, Option2.x, Option2.y, WHITE);
                        DrawText("Connect the elements of: Hydrochloric Acid", 390, 150, 20, WHITE);
                    }
                    else if (resetcounter == 2) {
                        DrawTexture(textbg2, 380, 115, WHITE);
                        DrawRectangle(475, 215, 100, 75, WHITE);
                        DrawRectangle(650, 215, 100, 75, WHITE);
                        DrawTexture(Cl, Option1.x, Option1.y, WHITE);
                        DrawTexture(H, Option2.x, Option2.y, WHITE);
                        DrawText("Connect the elements of: Sodium Chloride", 400, 150, 20, WHITE);
                    }


                }
                CheckIfWinOrLose(gamestop, deleteEnemy1, collision, enemy.EnemyHealth, player.Health);
            }

            Moving(collision, player.x, player.y, movespeed, timer, framePlayer, maxFramesPlayer, frameWidthPlayer, character, characterLeft);
            MoveAnimation(timer2, frameEnemy, maxFramesEnemy, frameWidthEnemy, Enemy, enemy.x, enemy.y);
            EndDrawing();
        }
        // De-Initialization
        CloseWindow();
        return 0;
    }