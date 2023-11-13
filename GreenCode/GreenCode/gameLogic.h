#pragma once

#include "raylib.h"

void CheckIfWinOrLose(bool& gamestop, bool& deleteEnemy1, bool& collision, int& EnemyHealth, int& Health);
bool ChooseRectangle(Rectangle rectangle);
void DrawHealth(int Health, int EnemyHealth);