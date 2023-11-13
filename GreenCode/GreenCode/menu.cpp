//#include "Normal.h"
//
//using namespace std;
//
//bool ChooseRectangle(Rectangle rectangle) {
//    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//        if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {
//            return true;
//        }
//    }
//}
//
//int main() {
//    const int screenWidth = 1199;
//    const int screenHeight = 800;
//
//    InitWindow(screenWidth, screenHeight, "GreenCode Game");
//
//    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
//
//    Texture2D backg = LoadTexture("resources/blurred.png");
//    Texture2D button1 = LoadTexture("resources/Play.png");
//    Texture2D button2 = LoadTexture("resources/Exit.png");
//    Texture2D button3 = LoadTexture("resources/Normal.png");
//    Texture2D button4 = LoadTexture("resources/Hard.png");
//
//    Rectangle PlayButton = { screenWidth / 2 - 250, screenHeight / 2 - 50, 250, 100 };
//    Rectangle QuitButton = { screenWidth / 2 - 130, screenHeight / 2 + 100, 250, 100 };
//    Rectangle Hard = { screenWidth / 2 - 250, screenHeight / 2 + 100, 250, 100 };
//    bool clicked = false;
//
//    // Main game loop
//    while (!WindowShouldClose())    // Detect window close button or ESC key
//    {
//        DrawTexture(backg, screenWidth / 2 - 599, screenHeight / 2 - 398, WHITE);
//        // Draw
//        //----------------------------------------------------------------------------------
//        BeginDrawing();
//        if (ChooseRectangle(PlayButton)) {
//            clicked = true;
//        }
//        if (!clicked) {
//            DrawTexture(button1, screenWidth / 2 - 250, screenHeight / 2 - 50, WHITE);
//            DrawTexture(button2, screenWidth / 2 - 130, screenHeight / 2 + 100, WHITE);
//        }
//        if (clicked) {
//            DrawTexture(button3, screenWidth / 2 - 250, screenHeight / 2 - 50, WHITE);
//            DrawTexture(button4, screenWidth / 2 - 250, screenHeight / 2 + 100, WHITE);
//            if (ChooseRectangle(PlayButton)) {
//                normal();
//            }
//            if (ChooseRectangle(Hard)) {
//                hard();
//            }
//        }
//
//        if (ChooseRectangle(QuitButton) && !clicked) {
//            EndDrawing();
//            CloseWindow();
//            return 0;
//        }
//        EndDrawing();
//    }
//    // De-Initialization
//    CloseWindow();
//    return 0;
//}