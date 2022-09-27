#ifndef GAME
#define GAME

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "raylib.h"

#define SCREEN_SIZE 800
#define MARGIN 50
#define UTIL_GRID_SPACE (SCREEN_SIZE - MARGIN)

typedef struct Cell {
    Vector2 position;
    int alive;
    int neighborhoods;
} Cell;

Cell** initGame(int* size);
void drawGame(Cell** grid, int size);

#endif