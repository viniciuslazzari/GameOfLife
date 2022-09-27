#include "game.h"

const char* gameFile = "game.txt";

Cell** createGrid(int size){    
    Cell** grid = (Cell **)malloc(size * sizeof(Cell *)); 

    for (int i = 0; i < size; i++) {
        grid[i] = (Cell *)malloc(size * sizeof(Cell));
    }

    return grid;
}

Cell** initGame(int* size){
    char temp;
    FILE* file = fopen(gameFile, "r");

    fscanf(file, "%d\n", size);

    Cell** grid = createGrid(*size); 

    float cellSize = UTIL_GRID_SPACE / *size;

    for (int i = 0; i < *size; i++){
        for (int j = 0; j < *size; j++){
            grid[i][j].position = (Vector2) { j * cellSize + MARGIN, i * cellSize + MARGIN };
            grid[i][j].neighborhoods = 0;

            fscanf(file, "%c ", &temp);

            grid[i][j].alive = 0;

            if (temp == 'X') grid[i][j].alive = 1;
        }
    }

    return grid;
}

void updateCellsStates(Cell** grid, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (grid[i][j].alive == 1 && (grid[i][j].neighborhoods == 2 || grid[i][j].neighborhoods == 3)){
                grid[i][j].alive = 1;
                continue;
            }

            if (grid[i][j].alive == 0 && grid[i][j].neighborhoods == 3){
                grid[i][j].alive = 1;
                continue;
            }

            grid[i][j].alive = 0;
        }
    }
}

void updateCellNeighborhoods(Cell** grid, int size){
    int sum;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            sum = 0;

            for (int x = i - 1; x <= i + 1; x++){
                for (int y = j - 1; y <= j + 1; y++){
                    if (x == i && y == j) continue;
                    if (x < 0 || x > size - 1 || y < 0 || y > size - 1) continue;

                    sum += grid[x][y].alive;
                }
            }

            grid[i][j].neighborhoods = sum;
        }
    }
}

void drawGrid(Cell** grid, int size){
    float cellSize = UTIL_GRID_SPACE / size;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
        {
            if (grid[i][j].alive == 1) DrawRectangle(grid[i][j].position.x, grid[i][j].position.y, cellSize, cellSize, WHITE);
        }
    }
}

void drawGame(Cell** grid, int size){
    updateCellNeighborhoods(grid, size);

    updateCellsStates(grid, size);

    drawGrid(grid, size);
};