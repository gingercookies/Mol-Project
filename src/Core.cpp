#include "Core.h"

#include <random>

#include "Blockcompoments.cpp"
#include "Grid.h"
using namespace std;
Core::Core() {
    grid = Grid();
    blocks = getBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
};

Block Core::getRandomBlock() {
    if (blocks.empty()) {
        blocks = getBlocks();
    }
    int random = rand() % blocks.size();
    Block block = blocks[random];
    blocks.erase(blocks.begin() + random);
    return block;
}

vector<Block> Core::getBlocks() {
    return {BlockL(), BlockS(), BlockZ(), BlockT(), BlockJ()};
}

void Core::Draw() {
    grid.Draw();
    currentBlock.Draw();
    // nextBlock.Draw();
}

void Core::Input() {
    int key = GetKeyPressed();
    switch (key) {
        case KEY_DOWN:
            MoveDown();
            break;
        case KEY_LEFT:
            MoveLeft();
            break;
        case KEY_RIGHT:
            MoveRight();
            break;
        case KEY_SPACE:
            break;
    }
}

// Input
void Core::MoveLeft() {
    currentBlock.Move(0, -1);
    if (CheckBlockOutside()) {
        currentBlock.Move(0, 1);
    }
}
void Core::MoveRight() {
    currentBlock.Move(0, 1);
    if (CheckBlockOutside()) {
        currentBlock.Move(0, -1);
    }
}
void Core::MoveDown() {
    currentBlock.Move(1, 0);
    if (CheckBlockOutside()) {
        currentBlock.Move(-1, 0);
    }
}
bool Core::CheckBlockOutside() {
    vector<blockPos> cells = currentBlock.GetCellPositions();
    for (blockPos cell: cells) {
        if (grid.CheckCellsOutside(cell.row, cell.col)) {
            return true;
        }
    }
    return false;
}
