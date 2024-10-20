#include <iostream>

#include "Core.h"
#include "raylib.h"
using namespace std;
void Manual();
void GameOver(Core);
void DrawUI(Core);

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
        DrawUI(mainCore);
        Manual();
        // DrawText(("Sy Nghien"), 200, 650, 20, BLACK);

        mainCore.Draw();
        GameOver(mainCore);
        EndDrawing();
    }
    CloseWindow();
}
void Manual() {
    int fontSize = 15;
    int column1X = 10;
    int column2X = 230;
    int startY = 620;
    int lineHeight = 20;

    DrawText("Controls:", column1X, startY, fontSize, WHITE);
    DrawText("Left Arrow: Move Left", column1X, startY + lineHeight, fontSize, WHITE);
    DrawText("Right Arrow: Move Right", column1X, startY + 2 * lineHeight, fontSize, WHITE);
    DrawText("Down Arrow: Move Down", column1X, startY + 3 * lineHeight, fontSize, WHITE);
    DrawText("Space: Rotate/Up", column1X, startY + 4 * lineHeight, fontSize, WHITE);

    DrawText("R: Reset", column2X, startY + lineHeight, fontSize, WHITE);
    DrawText("-/+: Speed Change", column2X, startY + 2 * lineHeight, fontSize, WHITE);
}

void GameOver(Core mainCore) {
    const char* gameOverText = "Game Over";
    int gameOverTextWidth = MeasureText(gameOverText, 25);
    int gameOverX = 10 + (300 - gameOverTextWidth) / 2;
    if (mainCore.gameOver) {
        // Draw outline
        DrawText(gameOverText, gameOverX - 1, 249, 25, BLACK);
        DrawText(gameOverText, gameOverX + 1, 249, 25, BLACK);
        DrawText(gameOverText, gameOverX - 1, 251, 25, BLACK);
        DrawText(gameOverText, gameOverX + 1, 251, 25, BLACK);
        DrawText(gameOverText, gameOverX - 1, 250, 25, BLACK);
        DrawText(gameOverText, gameOverX + 1, 250, 25, BLACK);
        DrawText(gameOverText, gameOverX, 249, 25, BLACK);
        DrawText(gameOverText, gameOverX, 251, 25, BLACK);

        // Draw main text
        DrawText(gameOverText, gameOverX, 250, 25, WHITE);
    }
}

void DrawUI(Core tmp) {
    DrawRectangleLines(10, 10, 301, 601, WHITE);

    DrawText("Score", 330, 10, 35, WHITE);
    DrawRectangleRounded({320, 55, 120, 50}, 0.25, 0, WHITE);
    // DrawText(to_string(mainCore.score).c_str(), 376, 70, 25, BLACK);
    int scoreTextWidth = MeasureText(to_string(tmp.score).c_str(), 25);
    DrawText(to_string(tmp.score).c_str(), 320 + (120 - scoreTextWidth) / 2, 70, 25, BLACK);

    DrawText("Next", 340, 110, 35, WHITE);
    DrawText("Speed", 345, 280, 25, WHITE);
    DrawRectangleRounded({320, 315, 120, 40}, 0.25, 0, WHITE);
    tmp.getSetSpeed();

    DrawText("Rows", 355, 365, 25, WHITE);
    DrawRectangleRounded({320, 395, 120, 40}, 0.25, 0, WHITE);
    int rowsTextWidth = MeasureText(to_string(tmp.rowsCleared).c_str(), 25);
    DrawText(to_string(tmp.rowsCleared).c_str(), 320 + (120 - rowsTextWidth) / 2, 400, 25, BLACK);
}