#include "Grid.h"


bool Grid::IsRowFull(int row){
    for(int col = 0; col < 10 ;col ++ ){
        if(grid[row][col] == 0){
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row){
    for(int col = 0 ; col < 10; col++){
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numberRows){
    for(int col = 0 ; col < 10 ; col ++){
        grid[row + numberRows][col] = grid[row][col];
    }
    ClearRow(row);
}

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initalize();
    colors = GetCellColors();
    void Draw();
}

void Grid::Initalize(){
    colors = SetOriginalColors();
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            grid[i][j] = 0;
        }
    }
}



bool Grid::IsCellOutside(int row, int column){
    if(row >=0 && row < numRows && column >=0 && column < numCols){
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column){
    if(grid[row][column] == 0){
        return true;
    }
    return false;
}

int Grid::ClearFullRows(){
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

void Grid::Draw(){
    for(int i =0 ; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize + 10 , i * cellSize + 10, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}



