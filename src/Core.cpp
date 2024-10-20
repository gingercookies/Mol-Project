#include "Core.h"

#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

#include "Blockcompoments.cpp"
#include "Grid.h"
#include "raylib.h"

using namespace std;
Core::Core() {
    grid = Grid();
    blocks = getBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
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
    currentBlock.Draw(11, 11);
    switch (nextBlock.id) {
        case 6:  // I
            nextBlock.Draw(215, 152);
            break;
        case 7:  // O
            nextBlock.Draw(235, 180);
            break;
        default:
            nextBlock.Draw(217, 175);
            break;
    }
}

void Core::Input() {
    int key = GetKeyPressed();
    if (gameOver) {
        if (key == KEY_R) {
            Reset();
        }
        return;
    }
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
        case KEY_UP:
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
        case KEY_R:
            Reset();
            break;
    }
}

// Input
void Core::MoveLeft() {
    if (!gameOver) {
        currentBlock.Move(0, -1);
        if (CheckBlockOutside() || !CheckBlockCollision()) {
            currentBlock.Move(0, 1);
        }
    }
}
void Core::MoveRight() {
    if (!gameOver) {
        currentBlock.Move(0, 1);
        if (CheckBlockOutside() || !CheckBlockCollision()) {
            currentBlock.Move(0, -1);
        }
    }
}
void Core::MoveDown() {
    if (!gameOver) {
        currentBlock.Move(1, 0);
        if (CheckBlockOutside() || !CheckBlockCollision()) {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Core::getSetSpeed() {
    stringstream speed;
    speed << fixed << setprecision(1) << setSpeed;

    string speedStr = speed.str();
    const char* speedshow = speedStr.c_str();
    int speedTextWidth = MeasureText(speedshow, 25);
    DrawText(speedshow, 320 + (120 - speedTextWidth) / 2, 320, 25, BLACK);
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
    if (!gameOver) {
        currentBlock.Rotate();
        if (CheckBlockOutside() || !CheckBlockCollision()) {
            currentBlock.UndoRorate();
        }
    }
}

// setSpeed
void Core::increaseSpeed() {
    if (setSpeed > 0.2) {
        setSpeed -= 0.1;
    }
}
void Core::decreaseSpeed() {
    if (setSpeed < 1.2) {
        setSpeed += 0.1;
    }
}

void Core::LockBlock() {
    vector<blockPos> cells = currentBlock.GetCellPositions();
    for (blockPos cell: cells) {
        grid.grid[cell.row][cell.col] = currentBlock.id;
    }

    int tmp = grid.ClearFullRows();
    rowsCleared += tmp;
    score += tmp * tmp * 10;

    currentBlock = nextBlock;
    nextBlock = getRandomBlock();
    if (!CheckBlockCollision()) {
        gameOver = true;
    }
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

void Core::Reset() {
    grid.Init();
    blocks = getBlocks();
    score = 0;
    rowsCleared = 0;
    setSpeed = 1.00f;
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
}

bool Core::TimeTrigger(double interval) {
    if (GetTime() - lastUpd >= interval) {
        lastUpd = GetTime();
        return true;
    }
    return false;
}

void Core::fastMoveDown() {
    if (IsKeyDown(KEY_DOWN)) {
        if (TimeTrigger(fastSpeedMultiplier)) {
            MoveDown();
            if (!gameOver) score++;
        }
    } else {
        if (TimeTrigger(setSpeed)) {
            MoveDown();
        }
    }
}