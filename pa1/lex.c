// #include "lex.h"

// int lookup(char ch) 
// {
//     lexLen = 0;
//     switch (ch)
//     {
//     case '(':
//         addChar(lexLen);
//         nextToken = LEFT_PAR;
//         break;

//     case ')':
//         addChar(lexLen);
//         nextToken = RIGHT_PAR;
//         break;
//     case '+':
//         addChar(lexLen);
//         nextToken = ADD_OP;
//         break;
//     case '-':
//         addChar(lexLen);
//         nextToken = SUB_OP;
//         break;
//     case '*':
//         addChar(lexLen);
//         nextToken = MULT_OP;
//         break;
//     case '/':
//         addChar(lexLen);
//         nextToken = DIV_OP;
//         break;

//     default:
//         addChar(lexLen);
//         nextToken = EOF;
//         break;
//     }
//     return nextToken;
// }

// void addChar(int lexLen)
// {
//     lexLen = strlen(lexeme);
//     if (lexLen <= 98)
//     {
//         lexeme[lexLen+1] = nextChar;
//         lexeme[lexLen] = 0;
//     }
//     else
//         printf("Error - lexeme is too long \n");
// }

// void getChar(FILE *inFile)
// {
//     if ((nextChar = getc(inFile)) != EOF)
//     {   // this part of the code will be used in pa2
//         if(isalpha(nextChar))
//         {
//             charClass = LETTER;
//         }
//     }
//     // this part of the code will be used in pa2
//     else if (isdigit(nextChar))
//     {
//         charClass = DIGIT;
//     }

//     else
//         charClass = EOF;
// }

// void skipSpace()
// {
//     while(isspace(nextChar))
//     {
//         getChar(inFile);
//     }
// }

// int lex()
// {
//     lexLen = 0;
//     skipSpace();
//     switch (charClass)
//     {
//     case LETTER:
//         addChar(lexLen);
//         getChar(inFile);
//         while (charClass == LETTER || charClass == DIGIT)
//         {
//             addChar(lexLen);
//             getChar(inFile);
//         }
//         nextToken = IDENT;
//         break;
    
//     case DIGIT:
//         addChar(lexLen);
//         getChar(inFile);
//         while (charClass == DIGIT)
//         {
//             addChar(lexLen);
//             getChar(inFile);
//         }
//         nextToken = INT_LIT;
//         break;
    
//     case UNKNOWN:
//         lookup(nextChar);
//         getChar(inFile);
//         break;
    
//     case EOF:
//         nextToken = EOF;
//         lexeme[0] = 'E';
//         lexeme[1] = 'O';
//         lexeme[2] = 'F';
//         lexeme[3] = 0;
//         break;

//     printf("The token is:%d, The lexeme is:%s\n,"
//     , nextToken, lexeme);
//     }
// }

