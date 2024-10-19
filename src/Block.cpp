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

void Block::Rotate() {
    rotationState++;
    // vì chỉ có 4 trạng thái, nên lần tiếp theo chuyển về 0
    if (rotationState == static_cast<int>(cells.size())) {
        rotationState = 0;
    }
}

void Block::UndoRorate() {
    rotationState--;
    if (rotationState == -1) {
        rotationState = static_cast<int>(cells.size()) - 1;
    }
}
