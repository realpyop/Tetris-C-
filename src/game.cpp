#include "game.hpp"
#include <random>
#include <iostream>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();

    // Debugging Block not drawing on Grid
    std::cout << "Current Block is initialized at : ";
    for (const auto& pos : currentBlock.GetCellsPosition())
    {
        std::cout << "(" << pos.row << "," << pos.col << ")";
    }
    std::cout << std::endl;
    gameOver = false;
    score = 0;

};

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block randomBlock = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);

    return randomBlock;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}; 

void Game::Draw()
{    
    grid.Draw();
    currentBlock.Draw(11, 11);
    switch (nextBlock.id)
    {
        case 3:
            nextBlock.Draw(255,290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270,270);
            break;
    }

}

void Game::HandleInput() 
{
    int keypressed = GetKeyPressed();
    if(gameOver && keypressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keypressed)
    {
        case KEY_LEFT:
            MoveLeft();
            break;
        case KEY_RIGHT:
            MoveRight();
            break;
        case KEY_DOWN:
            MoveDown();
            UpdateScore(0, 1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }; 
};

void Game::MoveLeft()
{
    if(!gameOver)
    {
        currentBlock.Move(0,-1);
        if(isBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0,1); 
        }
    }
};

void Game::MoveRight()
{
    if(!gameOver)
    {
        currentBlock.Move(0,1);    
        if(isBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0,-1); 
        }
    }
};

void Game::MoveDown()
{
    if(!gameOver) {
        currentBlock.Move(1,0);  
        if(isBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}


bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellsPosition();

    for(Position item : tiles)
    {
        if(grid.isCellOutside(item.row, item.col))
        {
            return true;
        }
    }
    return false;
};

void Game::RotateBlock() 
{
    currentBlock.Rotate();
    if (isBlockOutside() || BlockFits() == false)
    {
        currentBlock.UndoRotate();
    }
}

void Game::LockBlock() 
{
    std::vector<Position> tiles  = currentBlock.GetCellsPosition();
    for (Position item : tiles)
    {
        grid.grid[item.row][item.col] = currentBlock.id;
    }

    currentBlock = nextBlock;
    if(BlockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRow();
    UpdateScore(rowsCleared, 0);

    
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellsPosition();
    for(Position item : tiles)
    {
        if(grid.isCellEmpty(item.row, item.col) == false)
        {
            return false;
        }
    }

    return true;
}

void Game::UpdateScore(int linecleared, int moveDownPoints)
{
    switch(linecleared)
    {
        case 1:
            score += 100;
            break; 
        case 2:
            score += 250;
            break; 
        case 3: 
            score += 500;
            break;
        case 4: 
            score += 1000; 
            break;
        default:
            break;
    }

    score += moveDownPoints; 
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}
