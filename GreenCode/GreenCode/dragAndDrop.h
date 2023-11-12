#pragma once

#include "raylib.h"
#include "gameStructures.h"

void CheckIfAnswerIsInTheSlot(bool& isinslot1, bool& isinslot2, Rectangle Option1, Rectangle Option2, Rectangle OptionSlot1, Rectangle OptionSlot2);
void NewObjective(int resetcounter, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, Rectangle Option1, Rectangle Option2, Rectangle OptionSlot1, Rectangle OptionSlot2);
void Moving(bool& collision, float& x, float& y, int movespeed, float& timer, int& framePlayer, int maxFramesPlayer, float frameWidthPlayer, Texture2D character, Texture2D characterLeft);
void DragNDropCheckAndDamage(bool& isinslot1, bool& isinslot2, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, bool& isSnapped, bool& turncheck, bool& dmgplayer, bool& dmgenemy, float* original1X, float* original1Y, float* original2X, float* original2Y, int& Health, int& EnemyHealth, int& counter, int& resetcounter);
// Other drag-and-drop-related functions
