#ifndef GAME
#define GAME

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "raylib.h"

#define SCREEN_SIZE 800
#define MAX 100
#define MARGIN 50
#define UTIL_GRID_SPACE (SCREEN_SIZE - MARGIN)
#define CELL_SIZE (UTIL_GRID_SPACE / MAX)

typedef struct Cell {
    Vector2 position;
    int alive;
    int neighborhoods;
} Cell;

void initGame(Cell grid[MAX][MAX]);
void drawGame(Cell grid[MAX][MAX]);

#endif