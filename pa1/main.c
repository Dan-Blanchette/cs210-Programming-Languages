/* Dan Blanchette
 * cs210 
 * Dr. Rinker
 * ( program start date: 14, sept 2020)
 * 
 * This program will identify and seperate all possible "words" 
 * as tokens from within a CCX code file. It will ignore all 
 * comment lines from the program.
 */

#include "lex.h"

int main()
{
    char fName[255];
    scanf("%s",fName);

    if((inFile = fopen("fName","r")) == NULL)
    {
        printf("Error - cannot open file \n");
    }
    else 
    {
        getChar();
        do
        {
            lex();
        }   while (nextToken != EOF);
    }
    fclose(inFile);
    return 0;
}

