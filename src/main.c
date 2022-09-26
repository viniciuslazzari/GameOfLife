#include "game.h"

int main(void){
    Cell grid[MAX][MAX];

    initGame(grid);

    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "Life");

    SetTargetFPS(5);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        drawGame(grid);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}