#pragma once
#include <map>
#include <vector>

#include "blockPos.h"
#include "color.h"
using namespace std;
class Block {
public:
    Block();
    void Draw();
    void Move(int row, int col);
    vector<blockPos> GetCellPositions();
    void Rotate();
    void UndoRorate();
    int id;
    map<int, vector<blockPos>> cells;

private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int colOffset;
};