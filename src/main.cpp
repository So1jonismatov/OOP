#include <raylib.h>
#include "Game.h"
#include "Colors.h"
#include <string>

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(){

    InitWindow(520,620,"OOP project");
    SetTargetFPS(60);
    Font font = LoadFontEx("fonts/Roboto_SemiCondensed-Bold.ttf",64, 0, 0 );

    Game game = Game(); 
    
    while (WindowShouldClose() == false){
        UpdateMusicStream(game.bgmusic);
        game.HandleInput();

        if(EventTriggered(0.4)){
            game.MoveBlockDown();
        }
        
        BeginDrawing();
        ClearBackground(darkblue);
        DrawTextEx(font, "Score", {365,15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370,175}, 38, 2, WHITE);

        if(game.gameOver){
            game.GameOverHandle(font);
        }
        DrawRectangleRounded({320,55,190,60}, 0.3, 6, lightBlue);

        std::string scoreText = std::to_string(game.score);  

        Vector2 textSize = MeasureTextEx(font, scoreText.c_str(), 38, 2); 

        DrawTextEx(font, scoreText.c_str() , {320 + (190-textSize.x)/2 ,65}, 38, 2, WHITE);
        DrawRectangleRounded({320,215,190,180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }
    




    CloseWindow();


    return 0;
}