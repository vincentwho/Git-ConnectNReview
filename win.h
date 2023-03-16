#ifndef WIN_H
    #define WIN_H
    #include <stdbool.h>
    bool is_game_over(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
    bool someone_won(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
    bool someone_won_horizontally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
    bool someone_won_vertically(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
    bool someone_won_diagonally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
    bool someone_won_left_diagonally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
    bool someone_won_right_diagonally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
    bool tie(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win);
#endif