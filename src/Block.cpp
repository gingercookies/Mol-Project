#include "Block.h"

#include <raylib.h>

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
}

void Block::Draw() {
    vector<blockPos> currentCells = cells[rotationState];
    for (blockPos cell: currentCells) {
        DrawRectangle(cell.col * cellSize + 1, cell.row * cellSize + 1, cellSize, cellSize, colors[id]);
    }
}