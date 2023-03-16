/*
Program plays the game of Connect-"N", like Connect-4, but instead of original dimensions and number of pieces required to win,
players can decide the row, column dimnesions and number of pieces required to win. Player with piece 'X' takes their turn first.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "input_val.h"
#include "play.h"

/**
 * Main function. Sets up game.
 * @param argc: number of arguments from the terminal's initial run
 * @param argv: the arguments stored
 * @return: 0
*/
int main(int argc, char *argv[]){
    int row_dim, col_dim, num_pieces_to_win;
    char blank_char = '*'; 
    char** board;
    char* player_pieces;
    int player_turn;

    if(argc < 4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }else if(argc > 4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }else if(!areCorrectArguments(argv, 4)){
        printf("test\n");
        exit(0);
    }

    sscanf(argv[1], "%d", &row_dim);
    sscanf(argv[2], "%d", &col_dim);
    sscanf(argv[3], "%d", &num_pieces_to_win);

    setup_game(row_dim, col_dim, num_pieces_to_win, blank_char, &board, &player_turn, &player_pieces);
    play_game(board, row_dim, col_dim, blank_char, player_turn, player_pieces, num_pieces_to_win);
    clean_up(board, row_dim, col_dim, player_pieces); //clean dynamically allocated board and player pieces.
    return 0;
}