#pragma once

#include "raylib.h"
#include "gameStructures.h"

void CheckIfWinOrLose(bool& gamestop, bool& deleteEnemy1, bool& collision, int& EnemyHealth, int& Health);
void DrawHealth(int Health, int EnemyHealth);
