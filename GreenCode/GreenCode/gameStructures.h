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


#endif // GAME_STRUCTURES_H