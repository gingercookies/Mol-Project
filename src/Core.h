#pragma once
#include <vector>

#include "Block.h"
#include "Grid.h"
using namespace std;
class Core {
public:
    Core();
    Block getRandomBlock();
    vector<Block> getBlocks();
    void Draw();
    void Input();
    void MoveLeft();
    void MoveRight();
    void MoveDown();
    Grid grid;

private:
    bool CheckBlockOutside();
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};