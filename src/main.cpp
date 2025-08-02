#include <memory>
#include "raylib.h"
#include "../include/draw.h"
//#include "../include/board.hpp"

int main() {
    std::shared_ptr<Board> game_board {
        new Board (
            25, // Square edge
            0.3, // Square roundness
            2, // Dinstance between 2 squares
            BLACK, // Square color
            0.05, // Board roundness
            GRAY // Background color
        )
    };
    const int SCREEN_WIDTH = 2 * game_board->get_game_width();
    const int SCREEN_HEIGHT = game_board->get_game_height();
    int fps = 60;
    bool is_playing = false;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris"); // Set the game window width, height and title

    SetTargetFPS(fps); // Set the game FPS

    // Main game loop
    while( !WindowShouldClose() ){ // Detect window close button or ESC key
        BeginDrawing();

        draw(SCREEN_WIDTH, SCREEN_HEIGHT, is_playing, game_board);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}