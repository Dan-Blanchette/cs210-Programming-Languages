#ifndef LEXER_H
#define LEXER_H
#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

bool isDelimiter(char ch);
bool isOperator(char ch);
bool validIdentifier(char* str);
bool isKeyword(char* str);
bool isInteger(char* str);
bool isRealNumber(char* str);
char* subString(char* str, int left, int right);
void parse(char *str);


#endif