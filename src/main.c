#include "game.h"

const char* iconPath = "assets/icon.png";

int main(void){
    int size;
    Cell** grid;

    grid = initGame(&size);

    Image windowsIcon = LoadImage(iconPath);

    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "Life");

    SetWindowIcon(windowsIcon);

    SetTargetFPS(10);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        drawGame(grid, size);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}