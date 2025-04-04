#include "Block.h"

Block::Block(){
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Move(int rows, int columns){
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position>  Block::GetCellPositons (){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles){
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate(){
    rotationState++;
    if(rotationState == (int) cells.size()){
        rotationState = 0;
    }
}


void Block::UndoRotation(){
    rotationState--;
    if(rotationState < 0){
        rotationState = ((int) cells.size()) - 1;
    }
}

void Block::Draw(int offsetx, int offsety){
    std::vector<Position> tiles = GetCellPositons();
    for( Position item : tiles){
        DrawRectangle(item.column * cellSize  + offsetx , item.row * cellSize + offsety, cellSize - 1, cellSize - 1, colors[id]);
    }
}



