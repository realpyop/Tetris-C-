#include "block.hpp"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
}; 

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellsPosition();
    for(Position item : tiles)
    {
        DrawRectangle(item.col * cellSize + offsetX , item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int row, int col) 
{
    rowOffset += row;
    colOffset += col;
}

std::vector<Position> Block::GetCellsPosition() 
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles)
    {
        Position newPosition = Position(item.row + rowOffset, item.col + colOffset);
        movedTiles.push_back(newPosition);
    }

    return movedTiles;
}

void Block::Rotate()
{
    rotationState += 1;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotate()
{
    rotationState -= 1;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
