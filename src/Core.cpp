#include "Core.h"

#include <iostream>
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
    // int random = rand() % blocks.size();
    // Block block = blocks[random];
    // blocks.erase(blocks.begin() + random);
    // return block;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, blocks.size() - 1);

    int random = distr(gen);
    Block block = blocks[random];
    blocks.erase(blocks.begin() + random);
    return block;
}

vector<Block> Core::getBlocks() {
    return {BlockL(), BlockS(), BlockZ(), BlockT(), BlockJ(), BlockI(), BlockO()};
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
            RorateBlock();
            break;
        case KEY_MINUS:
            decreaseSpeed();
            cout << setSpeed << endl;
            break;
        case KEY_EQUAL:
            increaseSpeed();
            cout << setSpeed << endl;
            break;
    }
}

// Input
void Core::MoveLeft() {
    currentBlock.Move(0, -1);
    if (CheckBlockOutside() || !CheckBlockCollision()) {
        currentBlock.Move(0, 1);
    }
}
void Core::MoveRight() {
    currentBlock.Move(0, 1);
    if (CheckBlockOutside() || !CheckBlockCollision()) {
        currentBlock.Move(0, -1);
    }
}
void Core::MoveDown() {
    currentBlock.Move(1, 0);
    if (CheckBlockOutside() || !CheckBlockCollision()) {
        currentBlock.Move(-1, 0);
        LockBlock();
    }
}

// Tránh block tẩu thoát ra khỏi nhà giam 🐧
bool Core::CheckBlockOutside() {
    vector<blockPos> cells = currentBlock.GetCellPositions();
    for (blockPos cell: cells) {
        if (grid.CheckCellsOutside(cell.row, cell.col)) {
            return true;
        }
    }
    return false;
}

void Core::RorateBlock() {
    currentBlock.Rotate();
    if (CheckBlockOutside() || !CheckBlockCollision()) {
        currentBlock.UndoRorate();
    }
}

// setSpeed
void Core::increaseSpeed() {
    setSpeed -= 0.1;
    if (setSpeed <= 0.2) {
        setSpeed = 0.2;
    }
}
void Core::decreaseSpeed() {
    setSpeed += 0.1;
    if (setSpeed >= 1.2) {
        setSpeed = 1.2;
    }
}

void Core::LockBlock() {
    vector<blockPos> cells = currentBlock.GetCellPositions();
    for (blockPos cell: cells) {
        grid.grid[cell.row][cell.col] = currentBlock.id;
    }
    currentBlock = nextBlock;
    nextBlock = getRandomBlock();
}

bool Core::CheckBlockCollision() {
    vector<blockPos> cells = currentBlock.GetCellPositions();
    for (blockPos cell: cells) {
        if (!grid.CheckEmpty(cell.row, cell.col)) {
            return false;
        }
    }
    return true;
}
