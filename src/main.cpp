#include <raylib.h>
#include "Game.h"

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

    Color theblue = {44,44,127,255};
    InitWindow(300,600,"OOP project");
    SetTargetFPS(60);

    Game game = Game(); // blya
    
    while (WindowShouldClose() == false){
        game.HandleInput();

        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        
        BeginDrawing();
        ClearBackground(theblue);
        game.Draw();
        EndDrawing();
    }
    




    CloseWindow();


    return 0;
}