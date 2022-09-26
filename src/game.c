#include "game.h"

void initGame(Cell grid[MAX][MAX]){
    srand(time(NULL));

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            grid[i][j].position = (Vector2) { j * CELL_SIZE + MARGIN, i * CELL_SIZE + MARGIN };

            int r = rand() % 20;

            grid[i][j].alive = 0;

            if (r % 5 == 0) grid[i][j].alive = 1;
            
            grid[i][j].neighborhoods = 0;
        }
    }
}

void updateCellsStates(Cell grid[MAX][MAX]){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
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

void updateCellNeighborhoods(Cell grid[MAX][MAX]){
    int sum;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            sum = 0;

            for (int x = i - 1; x <= i + 1; x++){
                for (int y = j - 1; y <= j + 1; y++){
                    if (x == i && y == j) continue;
                    if (x < 0 || x > MAX - 1 || y < 0 || y > MAX - 1) continue;

                    sum += grid[x][y].alive;
                }
            }

            grid[i][j].neighborhoods = sum;
        }
    }
}

void drawGrid(Cell grid[MAX][MAX]){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++)
        {
            if (grid[i][j].alive == 1) DrawRectangle(grid[i][j].position.x, grid[i][j].position.y, CELL_SIZE, CELL_SIZE, WHITE);
        }
    }
}

void drawGame(Cell grid[MAX][MAX]){
    updateCellNeighborhoods(grid);

    updateCellsStates(grid);

    drawGrid(grid);
};