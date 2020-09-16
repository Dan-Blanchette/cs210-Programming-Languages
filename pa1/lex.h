#ifndef LEX_H
#define LEX_H

#include<stdio.h>
#include<ctype.h>

/* !! == remove from assignment, will be used in assignment 2 possibly */

/*!! character class types */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/*!! token macros */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAR 25
#define RIGHT_PAR 26


int charClass;
char lexeme[1024];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *inFile;

int lookup(char ch);
void addChar();
void getChar();
void rmvSpace();
int lex();


#endif