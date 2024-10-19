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
    void getSetSpeed();
    Grid grid;
    double setSpeed = 1;

private:
    bool CheckBlockOutside();
    void RorateBlock();
    void LockBlock();
    bool CheckBlockCollision();
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

    void increaseSpeed();
    void decreaseSpeed();
};