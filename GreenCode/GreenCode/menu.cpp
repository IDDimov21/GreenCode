#include "Normal.h"

using namespace std;

bool ChooseRectangle(Rectangle rectangle) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {
            return true;
        }
    }
}

int main() {
    const int screenWidth = 1199;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "GreenCode Game");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    Texture2D backg = LoadTexture("resources/blurred.png");
    Texture2D logo = LoadTexture("resources/logo.png");
    Texture2D button1 = LoadTexture("resources/Play.png");
    Texture2D button2 = LoadTexture("resources/Exit.png");

    Rectangle PlayButton = { screenWidth / 2 - 250, screenHeight / 2 - 50, 250, 100 };
    Rectangle QuitButton = { screenWidth / 2 - 130, screenHeight / 2 + 100, 250, 100 };

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        DrawTexture(backg, screenWidth / 2 - 599, screenHeight / 2 - 398, WHITE);
        DrawTexture(logo, screenWidth / 2 - 320, 120, WHITE);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        DrawTexture(button1, screenWidth / 2 - 250, screenHeight / 2 - 50, WHITE);
        DrawTexture(button2, screenWidth / 2 - 130, screenHeight / 2 + 100, WHITE);
        if (ChooseRectangle(PlayButton)) {
            CloseWindow();
            normal();
        }
        if (ChooseRectangle(QuitButton)) {
            EndDrawing();
            CloseWindow();
            return 0;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}