#pragma once
#include <raylib.h>

#include <vector>
using namespace std;

class Grid {
public:
    Grid();
    void Init();
    void Print();
    void Draw();
    bool CheckCellsOutside(int row, int col);
    bool CheckEmpty(int row, int col);
    int ClearFullRows();
    int grid[30][10];

private:
    bool CheckFull(int row);
    void clearRow(int row);
    void shiftRowsDown(int clearedrows);
    int numRows;
    int numCols;
    int cellSize;
    int completed = 0;
    vector<Color> colors;
};
