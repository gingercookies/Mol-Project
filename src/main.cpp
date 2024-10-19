#include <iostream>

#include "Grid.h"
#include "blockCompoments.cpp"
#include "raylib.h"

using namespace std;
int main() {
    Color background = {91, 91, 91, 255};
    InitWindow(451, 700, "Ehe");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    BlockI tmp = BlockI();

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(background);

        DrawRectangleLines(0, 0, 301, 601, WHITE);
        grid.Draw();
        tmp.Draw();

        DrawText("Sy Gei", 200, 650, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
}