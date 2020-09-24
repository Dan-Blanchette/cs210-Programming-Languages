#include "lexer.h"


// DRIVER FUNCTION 
int main(int argc, char **argv) 
{ 
    FILE *fp;
    char *buff = NULL;
    char ch;
    size_t size = 0;


    fp = fopen(argv[1],"r");
    
    if ( fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    rewind(fp);

    buff = malloc((size +1) * sizeof(*buff));
    fread(buff, size, 1, fp);
    buff[size] = '\0';
 

    fclose(fp);

    lex(buff); // calling the parse function 
	return (0); 
} 
