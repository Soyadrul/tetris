#include <memory>
#include "board.hpp"

#ifndef DRAW_H
#define DRAW_H

void draw_menu(const int& screen_width, const int& screen_height, bool& is_playing);
void draw_game(const int& screen_width, const int& screen_height, std::shared_ptr<Board> board);
void draw(const int& screen_width, const int& screen_height, bool& is_playing, std::shared_ptr<Board> board);

#endif // DRAW_H