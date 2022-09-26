#include "game.h"

const char* iconPath = "assets/icon.png";

int main(void){
    Cell grid[MAX][MAX];

    initGame(grid);

    Image windowsIcon = LoadImage(iconPath);

    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "Life");

    SetWindowIcon(windowsIcon);

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