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
    Sound rotateSound;
    Sound clearSound;

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
        if(!gameOver){
            
        
        currentBlock.Rotate();
        if(IsBlockOutside() || !IsBlockFits()){
            currentBlock.UndoRotation();
        }else{
            PlaySound(rotateSound);
        }
    }
        
    }

    void LockBlock(){
        std::vector<Position> tiles = currentBlock.GetCellPositons();
        for(Position item : tiles){
            grid.grid[item.row][item.column] = currentBlock.id;
        }
        currentBlock = nextBlock;
        if(!IsBlockFits()){
            gameOver = true;
        }
        nextBlock = GetRandomBlock();
        int rowsCleared = grid.ClearFullRows();
        if(rowsCleared > 0){
            PlaySound(clearSound);
            UpdateScore(rowsCleared, 0);
        }
        
    }

    bool IsBlockFits(){
        std::vector<Position> tiles = currentBlock.GetCellPositons();
        for(Position item : tiles){
            if(grid.IsCellEmpty(item.row, item.column) == false){
                return false;
            }    
        }
        return true;
    }

    void ResetGame(){
        PlayMusicStream(bgmusic);
        grid.Initalize();
        blocks = GetAllBlocks();
        currentBlock = GetRandomBlock();
        nextBlock = GetRandomBlock();
        score = 0;
        gameOverSoundPlayed = false;
    }
    void UpdateScore(int linesCleared, int moveDownPoints){
        switch (linesCleared)
        {
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
        default:
            break;
        }
        score+= moveDownPoints;
    }

    Block GetRandomBlock(){
        if(blocks.size() == 0){
            blocks = GetAllBlocks();
        }
        std::cout << rand() % blocks.size()  << std::endl;
        int randomIndex = rand() % blocks.size();
        Block block = blocks[randomIndex];
        blocks.erase(blocks.begin() + randomIndex);

        return block;
    }

    std::vector<Block> GetAllBlocks(){
        return {IBlock(), JBlock(), OBlock(), LBlock(), TBlock(), ZBlock(), SBlock()};
    }

    

    void MoveBlockLeft(){
        if(!gameOver){
            currentBlock.Move(0, -1);

            if(IsBlockOutside() || !IsBlockFits()){
                currentBlock.Move(0, 1);
            }
        }
        
    }

    void MoveBlockRight(){
        if(!gameOver){
            
        
        currentBlock.Move(0, 1);

        if(IsBlockOutside() || !IsBlockFits()){

            currentBlock.Move(0, -1);
        }
    }
    }

public:
    Grid grid;
    bool gameOver;
    int score;
    Music bgmusic;
    Sound gameOverSound;
    bool gameOverSoundPlayed;
    
    Game(){
        grid = Grid();
        blocks = GetAllBlocks();
        currentBlock = GetRandomBlock();
        nextBlock = GetRandomBlock();
        gameOver = false;
        score = 0;
        InitAudioDevice();
        bgmusic = LoadMusicStream("music/music.mp3");
        PlayMusicStream(bgmusic);
        rotateSound = LoadSound("music/rotate.mp3");
        clearSound = LoadSound("music/clear.mp3");
        gameOverSound = LoadSound("music/game_over.mp3");
        gameOverSoundPlayed = false;
        
    }

    ~Game(){
        UnloadMusicStream(bgmusic);
        UnloadSound(rotateSound);
        UnloadSound(clearSound);
        UnloadSound(gameOverSound);
        CloseAudioDevice();
        
    }



    void MoveBlockDown(){
        if(!gameOver){
        currentBlock.Move(1, 0);
        if(IsBlockOutside() || !IsBlockFits()){
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
    }
    void HandleInput(){
        int keyPressed = GetKeyPressed();
        if(gameOver && keyPressed != 0){
            gameOver = false;
            ResetGame();
        }
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
            UpdateScore(-1,1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
        }
    }

    void GameOverHandle(Font font){
        if(!gameOverSoundPlayed){
            StopMusicStream(bgmusic);
            PlaySound(gameOverSound);
            gameOverSoundPlayed = true;
        }
        DrawTextEx(font, "GAME OVER", {320,450}, 38, 2, RED);
    }

    
    
    void Draw(){
        grid.Draw();
        currentBlock.Draw(10,10);

        if(nextBlock.id == 3){ // Iblockni centrlash uchun
            nextBlock.Draw(265,290);
        }else if(nextBlock.id == 4){ // Oblockni centerlash uchun
            nextBlock.Draw(265,280);
        }else{
            nextBlock.Draw(280, 270);
        }
        
    }
};




#endif 