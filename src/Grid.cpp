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
            DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::CheckCellsOutside(int row, int col) {
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) return false;
    return true;
}

bool Grid::CheckEmpty(int row, int col) {
    if (grid[row][col] == 0) return true;
    return false;
}

int Grid::ClearFullRows() {
    completed = 0;
    for (int row = numRows - 1; row >= 0; row--) {
        if (CheckFull(row)) {
            clearRow(row);
            completed++;
        }
    }
    if (completed > 0) {
        shiftRowsDown();
    }
    return completed;
}

bool Grid::CheckFull(int row) {
    for (int col = 0; col < numCols; col++) {
        if (grid[row][col] == 0) return false;
    }
    return true;
}

void Grid::clearRow(int row) {
    for (int col = 0; col < numCols; col++) {
        grid[row][col] = 0;
    }
}

void Grid::shiftRowsDown() {
    // Dời hàng xuống
    for (int row = numRows - 1; row >= completed; row--) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = grid[row - completed][col];
        }
    }
    // Làm trống các hàng trên cùng
    for (int row = 0; row < completed; row++) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = 0;
        }
    }
}
