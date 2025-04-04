#ifndef GRID
#define GRID

#include <iostream>
#include <vector>
#include <raylib.h>
#include "Colors.h"

class Grid{
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
public:
    int grid [20][10];
    
    Grid(){
        numRows = 20;
        numCols = 10;
        cellSize = 30;
        Initalize();
        colors = GetCellColors();
        void Draw();
    }

    void Initalize(){
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                grid[i][j] = 0;
            }
        }
    }

    void Print(){

        // debug qilishga handonlar nima ekan deb uylamanglar
        
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < numCols; j++){
                std::cout << grid[i][j] <<" ";
            }
            std::cout << std::endl;
        }
    }


    bool IsCellOutside(int row, int column){
        if(row >=0 && row < numRows && column >=0 && column < numCols){
            return false;
        }
        return true;
    }


    void Draw(){
        for(int i =0 ; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                int cellValue = grid[i][j];
                DrawRectangle(j * cellSize  , i * cellSize , cellSize - 1, cellSize - 1, colors[cellValue]);
            }
        }

    }

};







#endif