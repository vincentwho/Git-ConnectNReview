#ifndef BOARD_H
    #define BOARD_H
    #include <stdlib.h>
    #include <stdbool.h>
    char** create_empty_board(int row_dim, int col_dim, char blank_char);
    void print_board(char** board, int row_dim, int col_dim);
    void delete_board(char** *board, int row_dim, int col_dim);
    void place_piece(char piece, char** board, char blank_char, int row_dim, int col_dim, int col);
    bool column_is_full(char** board, char blank_char, int row_dim, int col_dim, int col);
    bool move_is_on_board(char** board, char blank_char, int row_dim, int col_dim, int col);
    bool is_between(int value, int min_val, int max_val);
    bool all_same(char* values, int len, int num_pieces_to_win);
    bool left_diagonal_all_same(char** values, int row_dim, int col_dim, int num_pieces_to_win);
    bool right_diagonal_all_same(char** values, int row_dim, int col_dim, int num_pieces_to_win);
    char* get_column(char** board, int row_dim, int col);
#endif