#include "raylib.h"

#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square{
private:
    const int square_edge;
    const float square_roundness;
    const int square_segments;

public:
    Square(
        int _square_edge,
        float _square_roundness,
        int _square_segments
    );

    void draw_square(
        Color color,
        int x,
        int y
    );

    int get_edge() const;

    float get_roundness() const;

    int get_segments() const;
    
};

#endif // SQUARE_HPP