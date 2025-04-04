#ifndef BLOCK
#define BLOCK

#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"


class Block{
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;

public:
    int id;
    std::map<int, std::vector<Position>> cells;

    Block(){
        cellSize = 30;
        rotationState = 0;
        colors = GetCellColors();
        rowOffset = 0;
        columnOffset = 0;
    }
    
    void Move(int rows, int columns){
        rowOffset += rows;
        columnOffset += columns;
    }

    std::vector<Position>  GetCellPositons (){
        std::vector<Position> tiles = cells[rotationState];
        std::vector<Position> movedTiles;
        for(Position item: tiles){
            Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
            movedTiles.push_back(newPos);
        }
        return movedTiles;
    }

    void Rotate(){
        rotationState++;
        if(rotationState == (int) cells.size()){
            rotationState = 0;
        }
    }

    void UndoRotation(){
        rotationState--;
        if(rotationState < 0){
            rotationState = ((int) cells.size()) - 1;
        }
    }





    void Draw(){
        std::vector<Position> tiles = GetCellPositons();
        for( Position item : tiles){
            DrawRectangle(item.column * cellSize, item.row * cellSize, cellSize - 1, cellSize - 1, colors[id]);
        }
    }


     

    
};





#endif