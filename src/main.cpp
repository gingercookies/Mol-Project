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
        mainCore.fastMoveDown();

        BeginDrawing();
        ClearBackground(background);
        DrawRectangleLines(10, 10, 301, 601, WHITE);

        DrawText("Score", 330, 10, 35, WHITE);
        DrawRectangleRounded({320, 60, 120, 50}, 0.25, 0, WHITE);
        DrawText(to_string(mainCore.score).c_str(), 376, 75, 25, BLACK);

        DrawText("Next", 330, 150, 35, WHITE);
        DrawRectangleRounded({320, 240, 120, 120}, 0.1, 0, WHITE);

        DrawText("Speed", 330, 400, 35, WHITE);
        DrawRectangleRounded({320, 450, 120, 50}, 0.25, 0, WHITE);
        // DrawText(to_string(mainCore.getSetSpeed()).c_str(), 330, 85, 25, BLACK);

        DrawText(("An Gei"), 200, 650, 20, BLACK);

        mainCore.Draw();
        EndDrawing();
    }
    CloseWindow();
}