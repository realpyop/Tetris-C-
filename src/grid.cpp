#include "grid.hpp"
#include <iostream>
#include "colors.hpp"

Grid::Grid()
{
    numRow = 20;
    numCol = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for(int row = 0; row < numRow; row++)
    {
        for(int column = 0; column < numCol; column++)
        {
            grid[row][column] = 0;
        }
    }
}



void Grid::Print()
{
    for(int row = 0; row < numRow; row++)
    {
        for(int column = 0; column < numCol; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() 
{
    for(int row = 0; row < numRow; row++)
    {
        for (int col = 0; col < numCol; col++)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int column)
{
    if (row >= 0 && row < numRow && column >= 0 && column < numCol)
    {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }

    return false;
}

int Grid::ClearFullRow()
{
    int completed = 0;
    for (int row = numRow; row >= 0; row--)
    {
        if(isRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }

    return completed;
}

bool Grid::isRowFull(int row)
{
    for (int j = 0; j < numCol; j++)
    {
        if(grid[row][j] == 0)
        {
            return false; 
        }
    }
    
    return true;
}

void Grid::ClearRow(int row)
{
    for (int j = 0; j < numCol; j++)
    {
        grid[row][j] = 0;
    }
}

void Grid::MoveRowDown(int row, int rowsToClear)
{
    for (int j = 0; j < numCol; j++)
    {
        grid[row + rowsToClear][j] = grid[row][j];
        grid[row][j] = 0;
    }    
}
