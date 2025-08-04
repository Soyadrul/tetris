//#include "raylib.h"
#include "../include/board.hpp"

Board::Board(
    std::shared_ptr<Square> _square,
    int _two_squares_dinstance,
    Color _square_color,
    float _board_roundness,
    Color _background_color
):
    square{_square},
    two_squares_dinstance{_two_squares_dinstance},
    square_color{_square_color},
    board_roundness{_board_roundness},
    background_color{_background_color}
{
    board_border = 2 * two_squares_dinstance;
    board_width = ( square->get_edge() * squares_per_row ) + ( 2 * board_border ) + (squares_per_row - 1) * two_squares_dinstance;
    board_height = ( square->get_edge() * squares_per_column ) + ( 2 * board_border ) + (squares_per_column - 1) * two_squares_dinstance;
    square_x = board_x + board_border;
    square_y = board_y + board_border;
} // End of constructor

int Board::get_board_width() const {
    return board_width;
}

int Board::get_board_height() const {
    return board_height;
}

void Board::draw_background() {
    DrawRectangleRounded(
        {
            board_x,
            board_y,
            board_width,
            board_height
        },
        board_roundness,
        segments,
        background_color
    );
} // End of draw_background() method

void Board::draw_board_squares() {
    for(int i = 0; i < squares_per_row; ++i) {
        for(int j = 0; j < squares_per_column; ++j){

            DrawRectangleRounded(
                {
                    square_x + ( i * two_squares_dinstance ) + ( i * square->get_edge() ),
                    square_y + ( j * two_squares_dinstance ) + ( j * square->get_edge() ),
                    square->get_edge(),
                    square->get_edge()
                },
                square->get_roundness(),
                segments,
                square_color
            );

        }
    }
} // End of draw_squares() method