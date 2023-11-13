#pragma once
#include <iostream>
#include "raylib.h"
#include <string>

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

int normal();
int hard();