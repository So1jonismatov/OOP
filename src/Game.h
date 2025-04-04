#ifndef GAME
#define GAME

#include "Grid.h"
#include "Block.h"
#include "Blocks.h"
#include <random>

class Game{
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

    bool IsBlockOutside(){
        std::vector<Position> tiles = currentBlock.GetCellPositons();
        for(Position item : tiles){
            if(grid.IsCellOutside(item.row, item.column)){
                return true;
            }
        }
        return false;
    }

    void RotateBlock(){
        currentBlock.Rotate();
        if(IsBlockOutside()){
            currentBlock.UndoRotation();
        }
        
    }


public:
    Grid grid;
    
    Game(){
        grid = Grid();
        blocks = GetAllBlocks();
        currentBlock = GetRandomBlock();
        nextBlock = GetRandomBlock();
    }

    Block GetRandomBlock(){
        if(blocks.empty()){
            GetAllBlocks();
        }
        int randomIndex = rand() % blocks.size();
        Block block = blocks[randomIndex];
        blocks.erase(blocks.begin() + randomIndex);

        return block;
    }

    std::vector<Block> GetAllBlocks(){
        return {IBlock(), JBlock(), OBlock(), LBlock(), TBlock(), ZBlock(), SBlock()};
    }

    void HandleInput(){
        int keyPressed = GetKeyPressed();
        switch (keyPressed)
        {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;
        }
    }

    void MoveBlockLeft(){
        currentBlock.Move(0, -1);

        if(IsBlockOutside()){
            currentBlock.Move(0, 1);
        }
    }

    void MoveBlockRight(){
        currentBlock.Move(0, 1);

        if(IsBlockOutside()){

            currentBlock.Move(0, -1);
        }
    }

    void MoveBlockDown(){
        currentBlock.Move(1, 0);

        if(IsBlockOutside()){
            currentBlock.Move(-1, 0);
            LockBlock();

        }
    }

    void LockBlock(){
        std::vector<Position> tiles = currentBlock.GetCellPositons();
    }

    void Draw(){
        grid.Draw();
        currentBlock.Draw();
    }


    

};




#endif 