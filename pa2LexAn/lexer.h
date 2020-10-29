#ifndef LEXER_H
#define LEXER_H
#include <stdbool.h> 
#include <stdio.h> 
#include <ctype.h>
#include <string.h> 
#include <stdlib.h> 

/* ACKNOWLEDGEMENTS / RESOURCES used in the creation of this project */
// Geeksforgeeks.org
/* https://www.geeksforgeeks.org/c-program-detect-tokens-c-program/ */


bool isDelim(char ch);
bool isOp(char ch);
// bool isComm(char *str); // Needs implimentation 
// bool isStr(char *str);   // Needs implimentation
bool vIdent(char *str);
bool isKW(char* str);
bool isInt(char *str);
bool isRN(char *str);
char* sStr(char *str, int left, int right);
void lex(char *str);


#endif