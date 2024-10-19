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
    int grid[30][10];

private:
    int numRows;
    int numCols;
    int cellSize;
    vector<Color> colors;
};
