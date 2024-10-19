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
    void getSetSpeed();  // TODO: show this on screen
    void fastMoveDown();
    Grid grid;
    double setSpeed = 1.00f;

private:
    bool CheckBlockOutside();
    void RorateBlock();
    void LockBlock();
    bool CheckBlockCollision();
    float fastSpeedMultiplier = 0.2f;
    double lastUpd = 0;
    bool TimeTrigger(double interval);
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

    void increaseSpeed();
    void decreaseSpeed();
};