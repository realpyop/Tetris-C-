#pragma once

#include "grid.hpp"
#include "blocks.cpp"

class Game
{
    public:
        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        Grid grid;
        void HandleInput();
        void MoveLeft();
        void MoveRight();
        void MoveDown();
        bool gameOver;
        int score;

    private:
        bool isBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        void UpdateScore(int linecleared, int moveDownPoints);
        void Reset();

};
