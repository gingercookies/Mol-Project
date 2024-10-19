#include <iostream>

#include "Core.h"
#include "raylib.h"
using namespace std;
int main() {
    Color background = {91, 91, 91, 255};
    InitWindow(451, 700, "Ehe");
    SetTargetFPS(60);

    Core mainCore = Core();

    while (WindowShouldClose() == false) {
        mainCore.Input();
        BeginDrawing();
        ClearBackground(background);
        DrawRectangleLines(0, 0, 301, 601, WHITE);
        DrawText("Sy Gei", 200, 650, 20, BLACK);

        mainCore.Draw();
        EndDrawing();
    }
    CloseWindow();
}