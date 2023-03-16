#ifndef PLAY_H
    #define PLAY_H
    #include <stdbool.h>
    int get_starting_player_turn();
    char* get_player_pieces();
    void setup_game(int row_dim, int col_dim, int num_pieces_to_win, char blank_char, char** *out_board,
                    int *out_starting_player_turn, char* *out_player_pieces);
    void cur_player_take_turn(char** board, int row_dim, int col_dim, char blank_char, char cur_player_piece);
    void get_valid_move_from_player(char** board, int row_dim, int col_dim, char blank_char, 
                                    int *out_col);
    bool is_valid_move(int num_args_read, char** board, int row_dim, int col_dim, char blank_char, int col);
    void change_turns(int* cur_player_turn, int number_of_players);
    void announce_results(char** board, int row_dim, int col_dim, int cur_player_turn, char blank_char, int num_pieces_to_win);
    void play_game(char** board, int row_dim, int col_dim, char blank_char, int starting_player_turn,
                   char* player_pieces, int num_pieces_to_win);
    void clean_up(char** board, int row_dim, int col_dim, char* player_pieces);
#endif 