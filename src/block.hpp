#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <raylib.h>
#include <vector>
#include <map>
#include "colors.hpp"
#include "position.hpp"

class Block 
{
    public:
        Block();
        int id;
        std::map<int, std::vector<Position>> cells;
        void Draw(int offsetX, int offsetY);
        void Move(int row, int col);
        std::vector<Position> GetCellsPosition();
        void Rotate();
        void UndoRotate();

    private:
        int cellSize;
        int rotationState;
        std::vector<Color> colors;
        int rowOffset;
        int colOffset;
};

#endif