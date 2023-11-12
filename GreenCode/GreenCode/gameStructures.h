#ifndef GAME_STRUCTURES_H
#define GAME_STRUCTURES_H

#include "raylib.h"

struct Player {
    int Health;
    float x;
    float y;
};

struct Enemy {
    int EnemyHealth;
    float x;
    float y;
};

struct Option {
    float x;
    float y;
};

void DragNDrop(bool& collision, bool& isDragging, bool& isSnapped, bool& check1, Rectangle& Option, Rectangle& OptionSlot1, Rectangle& OptionSlot2);

#endif // GAME_STRUCTURES_H
