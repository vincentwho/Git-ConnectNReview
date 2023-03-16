#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "board.h"

/**
 * Taken from Tic-Tac-Toe Class Example. Function creates empty board by dynamic memory allocation.
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param blank_char: blank character '*' to fill board
*/
char** create_empty_board(int row_dim, int col_dim, char blank_char){
    char** board = (char**)calloc(row_dim, sizeof(char*));   //first, make space for row pointers
    for(int i = 0; i < row_dim; ++i){
        board[i] = (char*)calloc(col_dim, sizeof(char)); //last, create characters in that row
        for(int j = 0; j < col_dim; ++j){
            board[i][j] = blank_char;
        }
    }
    return board;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function prints board.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
*/
void print_board(char** board, int row_dim, int col_dim){
    //print board contents
    for(int i = 0; i < row_dim; ++i){
        printf("%d ", ((row_dim - 1) - i));
        for(int j = 0; j < col_dim; ++j){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    //print column headers
    printf("  ");
    for(int i = 0; i < col_dim; ++i){
        printf("%d ", i);
    }
    printf("\n");
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function deletes board memory space.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
*/
void delete_board(char** *board, int row_dim, int col_dim){
    for(int i = 0; i < row_dim; ++i){
        free((*board)[i]); //first, delete the characters in that row
    }
    free(*board);    //last, free space for row pointers
    (*board) = NULL;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function places player's piece.
 * @param piece: player's piece
 * @param board: the board
 * @param blank_char: blank character '*' to fill board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param col: player's specified column to play piece at
*/
void place_piece(char piece, char** board, char blank_char, int row_dim, int col_dim, int col){
    int row = 0;
    printf("PLACE_PIECE TEST 1");
    for(int i = row_dim; i > 0 ; i--){  //checks which row in selected column is available first starting from the bottom up (reversed).
        printf("PLACE_PIECE TEST 2");
        if(board[i][col] == blank_char){
            row = i;
        }else{
            break;
        }
    }
    printf("PLACE_PIECE TEST END");
    board[row][col] = piece;
}

/**
 * Function checks if column is full.
 * @param board: the board
 * @param blank_char: blank character '*' to fill board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param col: player's specified column to play piece at
*/
bool column_is_full(char** board, char blank_char, int row_dim, int col_dim, int col){
    printf("COLUMN_FULL TEST 1");
    for(int i = 0; i < row_dim; i++){
        if(board[i][col] == blank_char){
            return false;    //a column space is not full
        }
    }
    return true;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks if move on board is available.
 * @param board: the board
 * @param blank_char: blank character '*' to fill board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param col: player's specified column to play piece at
*/
bool move_is_on_board(char** board, char blank_char, int row_dim, int col_dim, int col){
    //return is_between(row, 0, dimensions - 1) &&
    //       is_between(col, 0, dimensions - 1);
    printf("MOVE_IS_ON_BOARD TEST 1");
    if(col < 0){ //checks if selected column negative
        return false;
    }else if(col >= col_dim){ //checks if selected column is greater than column dimensions
        return false;
    }else if(column_is_full(board, blank_char, row_dim, col_dim, col)){  //checks if seleteced column full
        return false;
    }
    return true;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks value is between a minimum and maximum value.
 * @param value: a value
 * @param min_val: specified minium value
 * @param max_val: specified maximum value
*/
bool is_between(int value, int min_val, int max_val){
    return value >= min_val && value <= max_val;
}

/**
 * Taken from Tic-Tac-Toe Class Example. Function checks indices are 
 * all the same piece and equal to number of pieces to win.
 * @param values: the iterated indices on the board
 * @param len: length to iterate over and check
 * @param num_pieces_to_win: user's number of pieces to win
*/
bool all_same(char* values, int len, int num_pieces_to_win){
    //all same pieces AND equal to number of peices to win
    int pieces = 0;
    for(int i = 1; i < len; ++i){
        if(values[i] != values[0]){
            return false;
        }else{
        pieces += 1;
        }
    }
    if(pieces != num_pieces_to_win){ //modified to check n pieces to win
        return false;
    }
    return true;
}

/**
 * Function checks if current left diagonal pieces are the same.
 * @param values: the itereated indices on the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param num_pieces_to_win: user's number of pieces to win
*/
bool left_diagonal_all_same(char** values, int row_dim, int col_dim, int num_pieces_to_win){
    int pieces = 0;
    for(int i = row_dim; i > 0; i--){
        for(int j = 0; j < col_dim; j++){
            if(values[i][j] != values[0][0]){
                return false;
            }else{
                pieces += 1;
            }
        }
    }
    if(pieces != num_pieces_to_win){ //modified to check n pieces to win
        return false;
    }
    return true;
}

/**
 * Function checks if current right diagonal pieces are the same.
 * @param values: the itereated indices on the board
 * @param row_dim: row dimensions
 * @param col_dim: column dimensions
 * @param num_pieces_to_win: user's number of pieces to win
*/
bool right_diagonal_all_same(char** values, int row_dim, int col_dim, int num_pieces_to_win){
    int pieces = 0;
    for(int i = 0; i < row_dim; i++){
        for(int j = col_dim; j > 0; j--){
            if(values[i][j] != values[0][col_dim-1]){
                return false;
            }else{
                pieces += 1;
            }
        }
    }
    if(pieces != num_pieces_to_win){ //modified to check n pieces to win
        return false;
    }
    return true;
}


/**
 * Taken from Tic-Tac-Toe Class Example. Function gets chosen column values.
 * @param board: the board
 * @param row_dim: row dimensions
 * @param col: user's specific column to play piece at
*/
char* get_column(char** board, int row_dim, int col){    //column values
    char* the_column = (char*)calloc(row_dim, sizeof(char));
    for(int i = 0; i < row_dim; ++i){
        the_column[i] = board[i][col];  
    }
    return the_column;
}