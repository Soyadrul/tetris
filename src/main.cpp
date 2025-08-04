#include <memory>
#include "raylib.h"
#include "../include/draw.h"
#include "../include/board.hpp"
#include "../include/piece/square.hpp"

int main() {
    const int square_edge = 25;
    const float square_roundness = 0.3;
    const int square_segments = 100;
    const int two_squares_dinstance = 2;
    const Color board_square_color = BLACK;
    const float board_roundness = 0.05;
    const Color board_background_color = GRAY;

    std::shared_ptr<Square> square {
        new Square (
            square_edge,
            square_roundness,
            square_segments
        )
    };

    std::unique_ptr<Board> game_board {
        new Board (
            square,
            two_squares_dinstance, // Dinstance between 2 squares
            board_square_color, // Square color
            board_roundness, // Board roundness
            board_background_color // Background color
        )
    };

    const int SCREEN_WIDTH = 2 * game_board->get_board_width();
    const int SCREEN_HEIGHT = game_board->get_board_height();
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