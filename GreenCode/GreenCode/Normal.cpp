#include "Normal.h"
#include "dragAndDrop.h"
#include "moveFunctions.h"
#include "gameLogic.h"
using namespace std;


int normal() {

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

    Rectangle OptionSlot1 = { 475, 190, 100, 75 };
    Rectangle OptionSlot2 = { 650, 190, 100, 75 };

    Rectangle Option1 = { option1.x, option1.y, 70, 70 };
    Rectangle Option2 = { option2.x, option2.y, 70, 70 };

    Rectangle QuitButton = { screenWidth / 2 - 130, screenHeight / 2 - 50, 250, 100 };

    float* original1X = &Option1.x, * original2X = &Option2.x, * original1Y = &Option1.y, * original2Y = &Option2.y;

    Texture2D background = LoadTexture("resources/background.png");
    Texture2D textbg = LoadTexture("resources/text1.png");
    Texture2D textbg2 = LoadTexture("resources/text2.png");
    Texture2D character = LoadTexture("resources/CharaWalk.png");
    Texture2D characterLeft = LoadTexture("resources/CharaWalkBack.png");
    Texture2D button2 = LoadTexture("resources/Exit.png");
    Texture2D Enemy = LoadTexture("resources/enemyPotion.png");
    Texture2D Scroll = LoadTexture("resources/scroll.png");
    Texture2D idle = LoadTexture("resources/idle.png");
    Texture2D H = LoadTexture("resources/H.png");
    Texture2D O = LoadTexture("resources/O.png");
    Texture2D Na = LoadTexture("resources/Na.png");
    Texture2D Cl = LoadTexture("resources/Cl.png");

    bool collision = false;
    bool isDragging2 = false;
    bool isDragging1 = false;
    bool isDragging3 = false;
    bool isDragging4 = false;
    bool isSnapped = false;
    bool isSnapped1 = false;
    bool isSnapped2 = false;
    bool isSnapped3 = false;
    bool isSnapped4 = false;
    bool turncheck = false;
    bool turncheck1 = false;
    bool turncheck2 = false;
    bool turncheck3 = false;
    bool turncheck4 = false;
    bool flag = false;
    bool Option1inCorrectSlot = false;
    bool Option2inCorrectSlot = false;
    bool Option3inCorrectSlot = false;
    bool Option4inCorrectSlot = false;
    bool gamestop = false;
    bool deleteEnemy1 = false;
    bool isinslot1 = false;
    bool isinslot2 = false;
    bool dmgplayer = false;
    bool dmgenemy = false;
    bool check = false;


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

        DragNDropCheckAndDamage(isinslot1, isinslot2, Option1inCorrectSlot, Option2inCorrectSlot, isSnapped1, turncheck1, dmgplayer, dmgenemy, original1X, original1Y, original2X, original2Y, player.Health, enemy.EnemyHealth, counter, resetcounter);
      
        CheckIfAnswerIsInTheSlot(isinslot1, isinslot2, Option1, Option2, OptionSlot1, OptionSlot2);

        NewObjective(resetcounter, Option1inCorrectSlot, Option2inCorrectSlot, Option1, Option2, OptionSlot1, OptionSlot2);

       


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
                        DrawTexture(Scroll, 380, 115, WHITE);
                        DrawRectangleLines(475, 190, 100, 75, BLACK);
                        DrawRectangleLines(650, 190, 100, 75, BLACK);
                        DrawTexture(H, Option1.x, Option1.y, WHITE);
                        DrawTexture(O, Option2.x, Option2.y, WHITE);
                        DrawText("Connect the elements of: Water", 435, 155, 22, BLACK);
                    }
                    else if (resetcounter == 1) {
                        DrawTexture(Scroll, 380, 115, WHITE);
                        DrawRectangleLines(475, 190, 100, 75, BLACK);
                        DrawRectangleLines(650, 190, 100, 75, BLACK);
                        DrawTexture(Cl, Option1.x, Option1.y, WHITE);
                        DrawTexture(Na, Option2.x, Option2.y, WHITE);
                        DrawText("Connect the elements of: Hydrochloric Acid", 425, 150, 18, BLACK);
                    }
                    else if (resetcounter == 2) {
                        DrawTexture(Scroll, 380, 115, WHITE);
                        DrawRectangleLines(475, 190, 100, 75, BLACK);
                        DrawRectangleLines(650, 190, 100, 75, BLACK);
                        DrawTexture(Cl, Option1.x, Option1.y, WHITE);
                        DrawTexture(H, Option2.x, Option2.y, WHITE);
                        DrawText("Connect the elements of: Sodium Chloride", 435, 150, 18, BLACK);
                    }


                }
                CheckIfWinOrLose(gamestop, deleteEnemy1, collision, enemy.EnemyHealth, player.Health);
                if (gamestop) {
                    DrawTexture(button2, screenWidth / 2 - 130, screenHeight / 2 - 50, WHITE);
                    if (ChooseRectangle(QuitButton)) {
                        EndDrawing();
                        CloseWindow();
                        return 0;
                    }
                }
            }
            if (!gamestop) {
                Moving(collision, player.x, player.y, movespeed, timer, framePlayer, maxFramesPlayer, frameWidthPlayer, character, characterLeft);
                MoveAnimation(timer2, frameEnemy, maxFramesEnemy, frameWidthEnemy, Enemy, enemy.x, enemy.y);
            }

            EndDrawing();
        }
        // De-Initialization
        CloseWindow();
        return 0;
    }