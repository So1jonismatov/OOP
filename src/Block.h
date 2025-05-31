#ifndef BLOCK
#define BLOCK

#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"


class Block{
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;

public:
    int id;
    std::vector<Color> colors;
    std::map<int, std::vector<Position>> cells;
    void Move(int rows, int columns);
    std::vector<Position>  GetCellPositons ();
    void Rotate();
    void UndoRotation();
    void Draw(int offsetx, int offsety);

    void SetNewColors(std::vector<Color> newColors){
        this -> colors = newColors;
    }
    
    Block();
};



#endif