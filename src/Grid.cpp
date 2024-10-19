#include "Grid.h"

#include <iostream>
#include <vector>

#include "color.h"
using namespace std;

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Init();
    colors = GetCellColors();
}

void Grid::Init() {
    // Khởi tạo giá trị cho mảng grid
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = 0;
        }
    }
}

// Check trạng thái của grid
void Grid::Print() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

void Grid::Draw() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::CheckCellsOutside(int row, int col) {
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) return false;
    return true;
}
