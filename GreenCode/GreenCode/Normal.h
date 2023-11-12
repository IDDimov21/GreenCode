#pragma once
#include <iostream>
#include "raylib.h"
#include <string>

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



void DragNDrop(bool& collision, bool& isDragging, bool& isSnapped, bool& check1, Rectangle& Option, Rectangle& OptionSlot1, Rectangle& OptionSlot2);