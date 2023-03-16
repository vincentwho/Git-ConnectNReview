#ifndef INPUT_VAL_H
    #define INPUT_VAL_H
    #include <stdbool.h>
    bool isValidFormat(const int numArgsRead, const int numArgsNeed);
    int getValidInt(const char* prompt);
    bool areCorrectArguments(char* argv[], const int numArgsNeed);
    bool isArgumentValidFormat(const int numArgsNeed, const int numArgsRead, bool end_newLine);
#endif