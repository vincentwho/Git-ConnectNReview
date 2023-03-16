#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "win.h"
#include "board.h"

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if game is over.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool is_game_over(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    printf("IS_GAME_OVER TEST 1");
    return someone_won(board, row_dim, col_dim, blank_char, num_pieces_to_win) || tie(board, row_dim, col_dim, blank_char, num_pieces_to_win);
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if someone won.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool someone_won(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    printf("SOMEONE_WON TEST 1");
    return someone_won_vertically(board, row_dim, col_dim, blank_char, num_pieces_to_win) ||
    someone_won_horizontally(board, row_dim, col_dim, blank_char, num_pieces_to_win) || 
    someone_won_diagonally(board, row_dim, col_dim, blank_char, num_pieces_to_win);
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if someone won horizontally.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool someone_won_horizontally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    for(int i = 0; i < row_dim; ++i){
        if(board[i][0] != blank_char && all_same(board[i], col_dim, num_pieces_to_win)){    //col_dim b/c checking horizonatlly
            return true;
        }
    }
    return false;   //return false at the end. for loop must check all rows first.
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if someone won vertically.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool someone_won_vertically(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    for(int i = 0; i < col_dim; ++i){
        char* col = get_column(board, row_dim, i);
        if(col[0] != blank_char && all_same(col, row_dim, num_pieces_to_win)){  //row_dim b/c checking vertically
            free(col);
            return true;
        }
        free(col);
    }
    return false;   //return false at the end. for loop must check all rows first.
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if someone won diagonally.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool someone_won_diagonally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    return someone_won_left_diagonally(board, row_dim, col_dim, blank_char, num_pieces_to_win) ||
           someone_won_right_diagonally(board, row_dim, col_dim, blank_char, num_pieces_to_win);
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if someone won left diagonally.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool someone_won_left_diagonally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    for(int i = row_dim; i > 0; i--){
        for(int j = 0; j < col_dim; j++){
            if(board[i][j] != blank_char && left_diagonal_all_same(board, row_dim, col_dim, num_pieces_to_win)){
                return true;
            }
        }
    }
    return false;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if someone won right diagonally.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool someone_won_right_diagonally(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    for(int i = 0; i < row_dim; i++){
        for(int j = col_dim; j > 0; j--){
            if(board[i][j] != blank_char && right_diagonal_all_same(board, row_dim, col_dim, num_pieces_to_win)){
                return true;
            }
        }
    }
    return false;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if game ends with a tie.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to initially fill the board
 * @param num_pieces_to_win: user's specified number of pieces to win
*/
bool tie(char** board, int row_dim, int col_dim, char blank_char, int num_pieces_to_win){
    if(someone_won(board, row_dim, col_dim, blank_char, num_pieces_to_win)){
        return false;
    }
    for(int i = 0; i < row_dim; ++i){   //for each row
        for(int j = 0; j < col_dim; ++j){    //for each column/ for each piece in the row
            if(board[i][j] == blank_char){
                return false;
            }
        }
    }
    return true;
}