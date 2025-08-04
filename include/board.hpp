#include <memory>
#include "piece/square.hpp"

#ifndef BOARD_HPP
#define BOARD_HPP

class Board{
private:
    // Square parameters
    std::shared_ptr<Square> square;
    int two_squares_dinstance;
    Color square_color;
    const int squares_per_row = 10;
    const int squares_per_column = 20;
    int square_x;
    int square_y;

    // Board parameters
    int board_border;
    float board_roundness;
    int segments;
    Color background_color;
    int board_width;
    int board_height;
    const int board_x = 0;
    const int board_y = 0;

public:
    Board(
        std::shared_ptr<Square> _square,
        int _two_squares_dinstance,
        Color _square_color,
        float _board_roundness,
        Color _background_color
    );

    int get_board_width() const;

    int get_board_height() const;

    void draw_background();

    void draw_board_squares();

};

#endif // BOARD_HPP