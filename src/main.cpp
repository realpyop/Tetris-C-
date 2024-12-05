#include <iostream>
#include <raylib.h>
#include "game.hpp"

using namespace std;

double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
};

int main () {

    cout << "Game started" << endl;

    // Create Screen
    int screen_width = 500;
    int screen_height = 620;
    InitWindow(screen_width, screen_height, "Tetris++");
    SetTargetFPS(60);

    // Loading font
    Font font = LoadFontEx("./font/monogram.ttf", 64, 0, 0);

    // Grid initialization
    Game game = Game();

    LBlock block = LBlock();

    // Game Loop
    while(!WindowShouldClose())
    {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(Color{44,44,127,255}); //Dark Blue

        // Update
        if(EventTriggered(0.2))
        {
            game.MoveDown();
        }

        // Draw

        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {365, 150}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.2, 0, LIGHTGRAY);
        
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, Color{44,44,127,255});


        DrawRectangleRounded({320, 215, 170, 180}, 0.2, 0, LIGHTGRAY);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}