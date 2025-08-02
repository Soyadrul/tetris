class Board{
private:
    const int segments = 100;

    // Square parameters
    int square_edge;
    float square_roundness;
    int two_squares_dinstance;
    Color square_color;
    const int squares_per_row = 10;
    const int squares_per_column = 20;
    int square_x;
    int square_y;

    // Board parameters
    int game_border;
    float game_roundness;
    Color background_color;
    int game_width;
    int game_height;
    const int game_x = 0;
    const int game_y = 0;

public:
    Board(
        int _square_edge = 22,
        float _square_roundness = 0.5,
        int _two_squares_dinstance = 5,
        Color _square_color = BLACK,
        float _game_roundness = 0.05,
        Color _background_color = GRAY
    );

    int get_game_width() const;

    int get_game_height() const;

    void draw_background();
    void draw_squares();

};