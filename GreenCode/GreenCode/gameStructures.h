#ifndef GAME_STRUCTURES_H
#define GAME_STRUCTURES_H

#include "raylib.h"

struct Player {
    float x;
    float y;
    int Health;
};

struct Enemy {
    float x;
    float y;
    int EnemyHealth;
    bool isAlive;
};

struct Option {
    float x;
    float y;
};

void DragNDrop(bool& collision, bool& isDragging, bool& isSnapped, bool& check1, Rectangle& Option, Rectangle& OptionSlot1, Rectangle& OptionSlot2);

#endif // GAME_STRUCTURES_H
