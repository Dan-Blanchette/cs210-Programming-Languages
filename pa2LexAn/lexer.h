#ifndef LEXER_H
#define LEXER_H
#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

bool isDelim(char ch);
// bool isComm(char *ch); Needs to be implmented
// bool isStr(char ch);   Needs to be implmented
bool isOp(char ch);
bool isOp2(char *str);
bool vIdent(char *str);
bool isKW(char* str);
bool isInt(char *str);
bool isRN(char *str);
char* sStr(char *str, int left, int right);
void lex(char *str);


#endif