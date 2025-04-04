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

    bool IsRowFull(int row){
        for(int col = 0; col < 10 ;col ++ ){
            if(grid[row][col] == 0){
                return false;
            }
        }
        return true;
    }

    void ClearRow(int row){
        for(int col = 0 ; col < 10; col++){
            grid[row][col] = 0;
        }
    }

    void MoveRowDown(int row, int numberRows){
        for(int col = 0 ; col < 10 ; col ++){
            grid[row + numberRows][col] = grid[row][col];
        }

        ClearRow(row);
    }

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

    bool IsCellEmpty(int row, int column){
        if(grid[row][column] == 0){
            return true;
        }
        return false;
    }

    int ClearFullRows(){
        int completed = 0;
        for(int i = 19 ; i >=0 ; i--){
            if(IsRowFull(i)){
                ClearRow(i);
                completed ++ ;
            }else if(completed > 0){
                MoveRowDown(i, completed);
            }
        }
        return completed;
    }


    void Draw(){
        for(int i =0 ; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                int cellValue = grid[i][j];
                DrawRectangle(j * cellSize + 10 , i * cellSize + 10, cellSize - 1, cellSize - 1, colors[cellValue]);
            }
        }

    }

};







#endif