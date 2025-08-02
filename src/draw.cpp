#include <string>
#include "raylib.h"
#include "../include/draw.h"



void draw_menu(const int& screen_width, const int& screen_height, bool& is_playing) {
    ClearBackground(RAYWHITE);

    // Set rectangles position
    const int rec_width = screen_width / 2;
    const int rec_height = screen_height / 10;
    const int rec_x = (screen_width - rec_width) / 2;
    const int rec_y = (screen_height - rec_height) / 2;
    const int shadow_correction = 4;
    Rectangle rec {
        rec_x,
        rec_y,
        rec_width,
        rec_height
    };
    Rectangle shadow {
        rec_x + shadow_correction,
        rec_y + shadow_correction,
        rec_width,
        rec_height
    };

    // Set Rectangle parameters
    constexpr float roundness = 0.5;
    constexpr int segments = 1;
    constexpr float lineThick = 2.5;
    constexpr Color color = RED;
    constexpr Color shadow_color = GRAY;    

    // Set text (inside the button) parameters
    std::string text_inside_button = "Play!";
    constexpr int font_size = 20;
    const int text_width = MeasureText(text_inside_button.c_str(), font_size);
    const int text_height = font_size;
    const Color text_color = BLACK;
    const int text_x = rec_x + ( (rec_width - text_width) / 2 );
    const int text_y = rec_y + ( (rec_height - text_height) / 2 );

    const int MOUSE_X = GetMouseX(); // Get the X position of the mouse
    const int MOUSE_Y = GetMouseY(); // Get the Y position of the mouse

    // Key pressed animation
    if(
        MOUSE_X >= rec_x &&
        MOUSE_X <= rec_x + rec_width &&
        MOUSE_Y >= rec_y &&
        MOUSE_Y <= rec_y + rec_height &&
        ( IsKeyDown(257) || IsKeyDown(32) )
    ) {
        DrawRectangleRounded(shadow, roundness, segments, color);
        DrawText(text_inside_button.c_str(), text_x + shadow_correction, text_y + shadow_correction, font_size, text_color);
    }
    // Switch to Game-mode if the selected key is pressed
    else if(
        MOUSE_X >= rec_x &&
        MOUSE_X <= rec_x + rec_width &&
        MOUSE_Y >= rec_y &&
        MOUSE_Y <= rec_y + rec_height &&
        ( IsKeyReleased(257) || IsKeyReleased(32) )
    ){
        is_playing = true;
    }
    // Normal (the key is not being pressed)
    else{
        DrawRectangleRounded(shadow, roundness, segments, shadow_color);
        DrawRectangleRounded(rec, roundness, segments, color);
        DrawText(text_inside_button.c_str(), text_x, text_y, font_size, text_color);
    }
}

void draw_game(const int& screen_width, const int& screen_height) {
    ClearBackground(RAYWHITE);

    std::string text_inside_button = "Game Mode";
    constexpr int font_size = 20;
    const int text_width = MeasureText(text_inside_button.c_str(), font_size);
    const int text_height = font_size;
    
    const int text_x = (screen_width - text_width) / 2;
    const int text_y = (screen_height - text_height) / 2;
    DrawText(text_inside_button.c_str(), text_x, text_y, font_size, LIGHTGRAY);
}

void draw(const int& screen_width, const int& screen_height, bool& is_playing) {
    if(is_playing) {
        draw_game(screen_width, screen_height);
    }
    else{
        draw_menu(screen_width, screen_height, is_playing);
    }
}