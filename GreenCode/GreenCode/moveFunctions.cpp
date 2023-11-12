#include "moveFunctions.h"
#include "raylib.h"

void Moving(bool& collision, float& x, float& y, int movespeed, float& timer, int& framePlayer, int maxFramesPlayer, float frameWidthPlayer, Texture2D character, Texture2D characterLeft) {
    if (!collision) {
        if (IsKeyDown('D')) {
            x += movespeed;
            MoveAnimation(timer, framePlayer, maxFramesPlayer, frameWidthPlayer, character, x, y);
        }
        else if (IsKeyDown('A')) {
            x -= movespeed;
            MoveAnimationBackwards(timer, framePlayer, maxFramesPlayer, frameWidthPlayer, characterLeft, x, y);
        }
        else {
            // Draw the default frame if no movement keys are pressed
            DrawTextureRec(character, Rectangle{ 0, 0, frameWidthPlayer, (float)character.height }, Vector2{ x, y }, RAYWHITE);
        }
    }
}

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

void barrier(float& x) {
    if (x <= 0.0f)
        x = 0.0f;
    if (x >= 1100.0f)
        x = 1100.0f;

}