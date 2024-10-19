#include "Block.h"

#include <raylib.h>

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    colOffset = 0;
    rowOffset = 0;
}

void Block::Draw() {
    vector<blockPos> currentCells = GetCellPositions();
    for (blockPos cell: currentCells) {
        DrawRectangle(cell.col * cellSize + 1, cell.row * cellSize + 1, cellSize, cellSize, colors[id]);
    }
}

void Block::Move(int row, int col) {
    rowOffset += row;
    colOffset += col;
}

vector<blockPos> Block::GetCellPositions() {
    vector<blockPos> currentCells = cells[rotationState];
    vector<blockPos> movedCells;

    for (blockPos cell: currentCells) {
        movedCells.push_back({cell.row + rowOffset, cell.col + colOffset});
    }
    return movedCells;
}