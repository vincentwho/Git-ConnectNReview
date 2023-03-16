#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "play.h"
#include "input_val.h"
#include "board.h"
#include "win.h"

/**
 * Taken from Tic-Tac-Toe Class Example. Function gets starting player turn.
*/
int get_starting_player_turn(){
    return 0; //0 means player 1, 1 means player 2.
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function gets player pieces.
*/
char* get_player_pieces(){
    char* player_pieces = calloc(3, sizeof(char));
    strcpy(player_pieces, "XO");
    return player_pieces;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function sets up game.
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param num_pieces_to_win: user's number of pieces to win
 * @param blank_char: blank character '*' to initially fill board
 * @param out_board: get modified board back
 * @param out_starting_player_turn: get determined starting player turn back
 * @param out_player_pieces: get determined player pieces back
*/
void setup_game(int row_dim, int col_dim, int num_pieces_to_win, char blank_char, char** *out_board,
                int *out_starting_player_turn, char* *out_player_pieces){
    char** board = create_empty_board(row_dim, col_dim, blank_char);
    int player_turn = get_starting_player_turn();
    char* player_pieces = get_player_pieces();
    *out_board = board;
    *out_starting_player_turn = player_turn;
    *out_player_pieces = player_pieces;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function responsible for current player's turn.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill board
 * @param cur_player_piece: current player's piece
*/
void cur_player_take_turn(char** board, int row_dim, int col_dim, char blank_char, char cur_player_piece){
    int col;
    print_board(board, row_dim, col_dim);
    get_valid_move_from_player(board, row_dim, col_dim, blank_char, &col);
    printf("CUR_PLAYER_TAKE_TURN TEST 1");
    place_piece(cur_player_piece, board, blank_char, row_dim, col_dim, col);
    printf("CUR_PLAYER_TAKE_TURN TEST 2");
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function gets valid move from player.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill board
 * @param out_col: gets back user's column to play piece at
*/
void get_valid_move_from_player(char** board, int row_dim, int col_dim, char blank_char, 
                                int *out_col){  //col pointer, to be modified and returned.
    int num_args_read;
    do{
        printf("Enter a column between 0 and %d to play in: ", (col_dim-1));
        num_args_read = scanf("%d", out_col);
        printf("GET_VALID_MOVE TEST 1");
    }while(!is_valid_move(num_args_read, board, row_dim, col_dim, blank_char, *out_col));
    printf("GET_VALID_MOVE TEST 2");
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if valid move.
 * @param num_args_read: number of arguments read
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill board
 * @param col: user's column to play piece at
*/
bool is_valid_move(int num_args_read, char** board, int row_dim, int col_dim, char blank_char, int col){
    const int num_args_needed = 1;
    printf("IS_VALID_MOVE TEST 1");
    return isValidFormat(num_args_read, num_args_needed) && move_is_on_board(board, blank_char, row_dim, col_dim, col);
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function changes the turn from current player to the other player.
 * @param cur_player_turn: current player turn referred to as 0 or 1
 * @param number_of_players: the number of players (2)
*/
void change_turns(int* cur_player_turn, int number_of_players){
    //if(cur_player_turn == 0){   //if player 1
    //    cur_player_turn = 1;
    //}else{
    //    cur_player_turn = 0;
    //}
    *cur_player_turn = (*cur_player_turn + 1) % number_of_players;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function announces results.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param cur_player_turn: current player's turn
 * @param num_pieces_to_win: user's number of pieces to win
 * @param blank_char: blank character '*' to initially fill board
*/
void announce_results(char** board, int row_dim, int col_dim, int cur_player_turn, char blank_char, int num_pieces_to_win){
    if(someone_won(board, row_dim, col_dim, blank_char, num_pieces_to_win)){
        if(cur_player_turn == 0){
            printf("Player 1 won!\n");
        }else{
            printf("Player 2 won!\n");
        }
    }else{
        printf("Tie game!\n");
    }
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function plays the game.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill board
 * @param starting_player_turn: starting player's turn
 * @param player_pieces: players' pieces
 * @param num_pieces_to_win: user's number of pieces to win
*/
void play_game(char** board, int row_dim, int col_dim, char blank_char, int starting_player_turn,
               char* player_pieces, int num_pieces_to_win){
    int cur_player_turn = starting_player_turn;
    const int num_players = 2;
    while(true){
        cur_player_take_turn(board, row_dim, col_dim, blank_char, player_pieces[cur_player_turn]);
        printf("PLAY_GAME TEST 1");
        if(is_game_over(board, row_dim, col_dim, blank_char, num_pieces_to_win)){
            printf("PLAY_GAME TEST 2");
            break;  //if game is over, stop the game play
        }
        change_turns(&cur_player_turn, num_players);
    }
    printf("PLAY_GAME TEST 3");
    print_board(board, row_dim, col_dim);
    announce_results(board, row_dim, col_dim, cur_player_turn, blank_char, num_pieces_to_win);
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function cleans allocated memory of the board and pieces.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param player_pieces: players' pieces
*/
void clean_up(char** board, int row_dim, int col_dim, char* player_pieces){
    printf("CLEAN_UP TEST 1");
    delete_board(&board, row_dim, col_dim);
    free(player_pieces);
}