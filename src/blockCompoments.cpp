#include "Block.h"
#include "blockPos.h"

// Khối chữ L
class BlockL : public Block {
public:
    BlockL() {
        id = 1;  // 1
        cells[0] = {blockPos(0, 2), blockPos(1, 0), blockPos(1, 1), blockPos(1, 2)};
        cells[1] = {blockPos(0, 1), blockPos(1, 1), blockPos(2, 1), blockPos(2, 2)};
        cells[2] = {blockPos(1, 0), blockPos(1, 1), blockPos(1, 2), blockPos(2, 0)};
        cells[3] = {blockPos(0, 0), blockPos(0, 1), blockPos(1, 1), blockPos(2, 1)};
        Move(0, 4);
    }
};

// Khối S
class BlockS : public Block {
public:
    BlockS() {
        id = 2;  // 2
        cells[0] = {blockPos(0, 1), blockPos(0, 2), blockPos(1, 0), blockPos(1, 1)};
        cells[1] = {blockPos(0, 0), blockPos(1, 0), blockPos(1, 1), blockPos(2, 1)};
        cells[2] = {blockPos(1, 1), blockPos(1, 2), blockPos(2, 0), blockPos(2, 1)};
        cells[3] = {blockPos(0, 0), blockPos(1, 0), blockPos(1, 1), blockPos(2, 1)};
        Move(0, 4);
    }
};
// Khối Z
class BlockZ : public Block {
public:
    BlockZ() {
        id = 3;  // 3
        cells[0] = {blockPos(0, 0), blockPos(0, 1), blockPos(1, 1), blockPos(1, 2)};
        cells[1] = {blockPos(0, 1), blockPos(1, 0), blockPos(1, 1), blockPos(2, 0)};
        cells[2] = {blockPos(1, 0), blockPos(1, 1), blockPos(2, 1), blockPos(2, 2)};
        cells[3] = {blockPos(0, 1), blockPos(1, 0), blockPos(1, 1), blockPos(2, 0)};
        Move(0, 4);
    }
};

// Khối T
class BlockT : public Block {
public:
    BlockT() {
        id = 4;  // 4
        cells[0] = {blockPos(0, 1), blockPos(1, 0), blockPos(1, 1), blockPos(1, 2)};
        cells[1] = {blockPos(0, 1), blockPos(1, 1), blockPos(1, 2), blockPos(2, 1)};
        cells[2] = {blockPos(1, 0), blockPos(1, 1), blockPos(1, 2), blockPos(2, 1)};
        cells[3] = {blockPos(0, 1), blockPos(1, 0), blockPos(1, 1), blockPos(2, 1)};
        Move(0, 4);
    }
};
// Khối J
class BlockJ : public Block {
public:
    BlockJ() {
        id = 5;
        cells[0] = {blockPos(0, 0), blockPos(1, 0), blockPos(1, 1), blockPos(1, 2)};
        cells[1] = {blockPos(0, 1), blockPos(0, 2), blockPos(1, 1), blockPos(2, 1)};
        cells[2] = {blockPos(1, 0), blockPos(1, 1), blockPos(1, 2), blockPos(2, 2)};
        cells[3] = {blockPos(0, 1), blockPos(1, 1), blockPos(2, 0), blockPos(2, 1)};
        Move(0, 4);
    }
};
// Khối I
class BlockI : public Block {
public:
    BlockI() {
        id = 6;
        cells[0] = {blockPos(0, 1), blockPos(1, 1), blockPos(2, 1), blockPos(3, 1)};
        cells[1] = {blockPos(2, 0), blockPos(2, 1), blockPos(2, 2), blockPos(2, 3)};
        cells[2] = {blockPos(0, 2), blockPos(1, 2), blockPos(2, 2), blockPos(3, 2)};
        cells[3] = {blockPos(1, 0), blockPos(1, 1), blockPos(1, 2), blockPos(1, 3)};
        Move(0, 4);
    }
};
// Khối O
class BlockO : public Block {
public:
    BlockO() {
        id = 7;
        cells[0] = cells[1] = cells[2] = cells[3] =
            {blockPos(0, 0), blockPos(0, 1), blockPos(1, 0), blockPos(1, 1)};
        Move(0, 4);
    }
};