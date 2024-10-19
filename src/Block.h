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
    int id;
    map<int, vector<blockPos>> cells;

private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
};