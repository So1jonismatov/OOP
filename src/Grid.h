#ifndef GRID
#define GRID

#include <vector>
#include <raylib.h>
#include "Colors.h"

class Grid{
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;

    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numberRows);

public:
    int grid [20][10];
    
    void Initalize();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    void Draw();

    void setColors(std::vector<Color> newcolors){
        this -> colors = newcolors;
    }
    
    Grid();
};







#endif