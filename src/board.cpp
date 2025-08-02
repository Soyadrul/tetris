#include "raylib.h"
#include "../include/board.hpp"


Board::Board(
    int _square_edge,
    float _square_roundness,
    int _two_squares_dinstance,
    Color _square_color,
    float _game_roundness,
    Color _background_color
):
    square_edge{_square_edge},
    square_roundness{_square_roundness},
    two_squares_dinstance{_two_squares_dinstance},
    square_color{_square_color},
    game_roundness{_game_roundness},
    background_color{_background_color}
{
    game_border = 2 * two_squares_dinstance;
    game_width = ( square_edge * squares_per_row ) + ( 2 * game_border ) + (squares_per_row - 1) * two_squares_dinstance;
    game_height = ( square_edge * squares_per_column ) + ( 2 * game_border ) + (squares_per_column - 1) * two_squares_dinstance;
    square_x = game_x + game_border;
    square_y = game_y + game_border;
} // End of constructor

int Board::get_game_width() const {
    return game_width;
}

int Board::get_game_height() const {
    return game_height;
}

void Board::draw_background() {
    DrawRectangleRounded(
        {
            game_x,
            game_y,
            game_width,
            game_height
        },
        game_roundness,
        segments,
        background_color
    );
} // End of draw_background() method

void Board::draw_squares() {
    for(int i = 0; i < squares_per_row; ++i) {
        for(int j = 0; j < squares_per_column; ++j){

            DrawRectangleRounded(
                {
                    square_x + ( i * two_squares_dinstance ) + ( i * square_edge ),
                    square_y + ( j * two_squares_dinstance ) + ( j * square_edge ),
                    square_edge,
                    square_edge
                },
                square_roundness,
                segments,
                square_color
            );

        }
    }
} // End of draw_squares() method