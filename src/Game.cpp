#include "Game.h"
#include <random>


bool Game::IsBlockOutside(){
    std::vector<Position> tiles = currentBlock.GetCellPositons();
    for(Position item : tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}

void Game::RotateBlock(){
    if(!gameOver){
        currentBlock.Rotate();
        if(IsBlockOutside() || !IsBlockFits())
            currentBlock.UndoRotation();
        else
            PlaySound(rotateSound);
    }
}

void Game::LockBlock(){
    std::vector<Position> tiles = currentBlock.GetCellPositons();
    for(Position item : tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(!IsBlockFits()){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    nextBlock.colors = Game::colors;
    int rowsCleared = grid.ClearFullRows();
    if(rowsCleared > 0){
        PlaySound(clearSound);
        UpdateScore(rowsCleared);
    }
}

bool Game::IsBlockFits(){
    std::vector<Position> tiles = currentBlock.GetCellPositons();
    for(Position item : tiles)
        if(grid.IsCellEmpty(item.row, item.column) == false)
            return false;
    return true;
}

void Game::ResetGame(){
    PlayMusicStream(bgmusic);
    Game::colors = SetOriginalColors();
    lastScore = 0;
    grid.Initalize();

    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
    gameOverSoundPlayed = false;

}

void Game::UpdateScore(int linesCleared){
    if(linesCleared == 1)
        score += 100;
    else if(linesCleared == 2)
        score += 300;
    else if(linesCleared >= 3)
        score += 250 * linesCleared - 1;
    
    if(score - lastScore > 100){
        lastScore = score;
        blocks = GetAllBlocks();
        colorChangeHandle();
        
        
    }
    
}



Block Game::GetRandomBlock(){
    if(blocks.size() == 0)
        blocks = GetAllBlocks();

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    block.colors = Game::colors;
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), OBlock(), LBlock(), TBlock(), ZBlock(), SBlock()};
}

void Game::MoveBlockLeft(){
    if(!gameOver){
        currentBlock.Move(0, -1);
        if(IsBlockOutside() || !IsBlockFits())
            currentBlock.Move(0, 1);
    }    
}

void Game::MoveBlockRight(){
    if(!gameOver){
        currentBlock.Move(0, 1);
        if(IsBlockOutside() || !IsBlockFits())
            currentBlock.Move(0, -1);
        
    }
}

Game::Game(){
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

Game::~Game(){
    UnloadMusicStream(bgmusic);
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadSound(gameOverSound);
    CloseAudioDevice();  
}

void Game::MoveBlockDown(){
    if(!gameOver){
        currentBlock.Move(1, 0);
        if(IsBlockOutside() || !IsBlockFits()){
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::HandleInput(){
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
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::GameOverHandle(Font font){
    if(!gameOverSoundPlayed){
        StopMusicStream(bgmusic);
        PlaySound(gameOverSound);
        gameOverSoundPlayed = true;
    }
    DrawTextEx(font, "GAME OVER", {320,450}, 38, 2, RED);
}


void Game::Draw(){
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