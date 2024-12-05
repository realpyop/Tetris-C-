#ifndef GRID_HPP
#define GRID_HPP

#include <raylib.h>
#include <vector>

class Grid {
public:
    Grid();
    int grid[20][10];
    void Initialize();
    void Print();
    void Draw();
    bool isCellOutside(int row, int column);
    bool isCellEmpty(int row, int column);
    int ClearFullRow(); 

private:
    int numRow;
    int numCol;
    int cellSize;
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    std::vector<Color> colors;
};

#endif