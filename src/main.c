#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "raylib.h"

#define MAX 100

typedef struct Cell {
    Vector2 position;
    int alive;
    int neighborhoods;
} Cell;

void initGame(Cell grid[MAX][MAX]){
    Vector2 cell = { 7, 7 };

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            grid[i][j].position = (Vector2) { j * cell.x + cell.x / 2 + 20, i * cell.y + 20 };

            int r = rand() % 20;

            grid[i][j].alive = 0;

            if (r % 5 == 0) grid[i][j].alive = 1;
            
            grid[i][j].neighborhoods = 0;
        }
    }
}

void updateCellState(Cell* cell){
    if (cell->alive == 1 && (cell->neighborhoods == 2 || cell->neighborhoods == 3)){
        cell->alive = 1;
        return;
    }

    if (cell->alive == 0 && cell->neighborhoods == 3){
        cell->alive = 1;
        return;
    }

    cell->alive = 0;
}

void updateCellNeighborhoods(Cell grid[MAX][MAX], int i, int j){
    int sum = 0;

    for (int x = i - 1; x <= i + 1; x++){
        for (int y = j - 1; y <= j + 1; y++){
            if (x == i && y == j) continue;
            if (x < 0 || x > MAX - 1 || y < 0 || y > MAX - 1) continue;

            sum += grid[x][y].alive;
        }
    }

    grid[i][j].neighborhoods = sum;
}

int main(void){
    const int screenWidth = 800;
    const int screenHeight = 800;
    Cell grid[MAX][MAX];

    srand(time(NULL));

    Vector2 cell = { 8, 8 };

    initGame(grid);

    InitWindow(screenWidth, screenHeight, "Life");

    SetTargetFPS(3);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                updateCellNeighborhoods(grid, i, j);
            }
        }

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                updateCellState(&grid[i][j]);
            }
        }

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                if (grid[i][j].alive == 1) DrawRectangle(grid[i][j].position.x - cell.x/2, grid[i][j].position.y - cell.y/2, cell.x, cell.y, WHITE);
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}