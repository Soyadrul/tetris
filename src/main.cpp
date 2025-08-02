#include "raylib.h"
#include "../include/draw.h"

int main() {
    constexpr int SCREEN_WIDTH = 450;
    constexpr int SCREEN_HEIGHT = 600;
    int fps = 60;
    bool is_playing = false;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris"); // Set the game window width, height and title

    SetTargetFPS(fps); // Set the game FPS

    // Main game loop
    while( !WindowShouldClose() ){ // Detect window close button or ESC key
        BeginDrawing();

        draw(SCREEN_WIDTH, SCREEN_HEIGHT, is_playing);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}