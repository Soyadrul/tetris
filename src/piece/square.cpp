#include "../../include/piece/square.hpp"

Square::Square(
    int _square_edge,
    float _square_roundness,
    int _square_segments
):
    square_edge{_square_edge},
    square_roundness{_square_roundness},
    square_segments{_square_segments}
{}

void Square::draw_square(Color color, int x, int y) {
    DrawRectangleRounded(
        {
            x,
            y,
            square_edge,
            square_edge
        },
        square_roundness,
        square_segments,
        color
    ); 
}

int Square::get_edge() const {
    return square_edge;
}

float Square::get_roundness() const {
    return square_roundness;
}

int Square::get_segments() const {
    return square_segments;
}