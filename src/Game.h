#ifndef GAME
#define GAME

#include "Grid.h"
#include "Block.h"
#include "Blocks.h"
#include "Colors.h"
#include <vector>

class Game{
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
    int lastScore = 0;

    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool IsBlockFits();
    void ResetGame();
    void UpdateScore(int linesCleared);
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();

public:
    Grid grid;
    bool gameOver;
    int score;
    Music bgmusic;
    Sound gameOverSound;
    bool gameOverSoundPlayed;
    std::vector<Color> colors = GetCellColors();

    
    void MoveBlockDown();
    void HandleInput();
    void GameOverHandle(Font font);

    void colorChangeHandle(){
        std::vector<Color> newColors = GetRandomCellColors();
        grid.setColors(newColors);
        currentBlock.colors = newColors;
        nextBlock.colors = newColors;
        for(Block block : blocks){
            block.SetNewColors(newColors);
        }
        Game::colors = newColors;
    }
    void Draw();

    Game();
    ~Game();
};




#endif 