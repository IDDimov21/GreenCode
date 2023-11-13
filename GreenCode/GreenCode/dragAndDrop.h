#pragma once

#include "raylib.h"
#include "gameStructures.h"

void DragNDrop(bool& collision, bool& isDragging, bool& isSnapped, bool& check1, Rectangle& Option, Rectangle& OptionSlot1, Rectangle& OptionSlot2);
void CheckIfAnswerIsInTheSlot(bool& isinslot1, bool& isinslot2, Rectangle Option1, Rectangle Option2, Rectangle OptionSlot1, Rectangle OptionSlot2);
void CheckIfAnswerIsInTheSlotHard(bool& isinslot1, bool& isinslot2, Rectangle Option1, Rectangle Option2, Rectangle Option3, Rectangle Option4, Rectangle OptionSlot1, Rectangle OptionSlot2);
void NewObjective(int resetcounter, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, Rectangle Option1, Rectangle Option2, Rectangle OptionSlot1, Rectangle OptionSlot2);
void NewObjectiveHard(int resetcounter, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, bool& Option3inCorrectSlot, bool& Option4inCorrectSlot, Rectangle Option1, Rectangle Option2, Rectangle Option3, Rectangle Option4, Rectangle OptionSlot1, Rectangle OptionSlot2);
void Moving(bool& collision, float& x, float& y, int movespeed, float& timer, int& framePlayer, int maxFramesPlayer, float frameWidthPlayer, Texture2D character, Texture2D characterLeft);
void DragNDropCheckAndDamage(bool& isinslot1, bool& isinslot2, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, bool& isSnapped, bool& turncheck, bool& dmgplayer, bool& dmgenemy, float* original1X, float* original1Y, float* original2X, float* original2Y, int& Health, int& EnemyHealth, int& counter, int& resetcounter);
void DragNDropCheckAndDamageHard(bool& isinslot1, bool& isinslot2, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, bool& isSnapped, bool& turncheck, bool& dmgplayer, bool& dmgenemy, float* original1X, float* original1Y, float* original2X, float* original2Y, float* original3X, float* original3Y, float* original4X, float* original4Y, int& Health, int& EnemyHealth, int& counter, int& resetcounter);
// Other drag-and-drop-related functions