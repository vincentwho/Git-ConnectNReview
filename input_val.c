#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "input_val.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
/**
 * Taken from Class Google Drivem Input Validation Examples. Function checks if input is valid.
 * @param numArgsRead: number of arguments read from input
 * @param numArgsNeed: number of arguments specified to be needed
*/
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); //45  bob  \n
    if(!isspace(character)){ //found a non whitespace character on the way to the end of the line
      formatIsGood = false;
    }
  }while(character != '\n'); //read characters until the end of the line
  return formatIsGood;
}

/**
 * Taken from Class Google Drivem Input Validation Examples. Function checks if input is a valid integer.
 * @param prompt: prompt used to ask user for input
*/
int getValidInt(const char* prompt){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num); // waffles 45\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

/**
 * Function checks if input is valid.
 * @param argv: number of arguments from the terminal's initial run
 * @param numArgsNeed: number of arguments specified to be needed
*/
bool areCorrectArguments(char* argv[], const int numArgsNeed){
  int numArgsReadSum = 0, current_num;
  for(int i = 1; i < numArgsNeed; i++){
    current_num = 0;
    numArgsReadSum += sscanf(argv[i], "%d", &current_num);
    if(current_num <= 0){ //check if negative or 0
      return false;
    }
  }
  if(!isArgumentValidFormat(numArgsNeed - 1, numArgsReadSum, false)){
    return false;
  }
  return true;
}

/**
 * Function checks if input is valid.
 * @param numArgsNeed: number of arguments specified to be needed
 * @param numArgsRead: number of arguments read from input
 * @param end_newLine: boolean value initialized to false. 
*/
bool isArgumentValidFormat(const int numArgsNeed, const int numArgsRead, bool end_newLine){
  bool isArgumentValidFormat = numArgsRead == numArgsNeed;
  if(end_newLine){
    char newLine;
    scanf("%c", &newLine);
    isArgumentValidFormat = (isArgumentValidFormat && newLine == '\n'); 
  }
  if(!isArgumentValidFormat){
    scanf("%*[^\n]"); //skip everything in the line until character is find

  }
  return isArgumentValidFormat;
}