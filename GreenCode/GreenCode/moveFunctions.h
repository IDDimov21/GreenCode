#pragma once

#include "raylib.h"

void MoveAnimation(float& timer, int& frame, int maxFrames, float frameWidth, Texture2D Run, float& x1, float& y1);
void MoveAnimationBackwards(float& timer, int& frame, int maxFrames, float frameWidth, Texture2D Run, float& x1, float& y1);
void barrier(float& x);
