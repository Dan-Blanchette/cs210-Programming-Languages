#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int makearg(char *s, char ***args);
int countW(char *ch);
void copyNChars(char *src, char *dest, int n);

#define MAX_STR_LEN 1024

int main(int argc, char **argv)
{
    FILE *fp;

    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    printf("\n");
    for (int i = 0; i < argc; ++i)
    {
        printf("%d: %s\n", argc, argv[i]);
    }

    fclose(fp);
    return 0;
}

int makearg(char *s, char ***args)
{
    assert(s != NULL);

    int argc = countW(s); 
    //printf("%d=%d\n", argc, countW(s));

    *args = (char**)malloc(sizeof(char*) * argc);

    int i = 0;
    int end = 0;
    char *startPtr = NULL;
    char *trackPtr = s;
    for(int j = 0; j < argc; ++j)
    {
        int strlen = 0;
        int startIndex = 0;
        
        while (isspace(*trackPtr))
        {
            ++trackPtr;
        }
        
        if (*trackPtr == '\0')
            break;

        startPtr = trackPtr;
        while (!isspace(*trackPtr) && *trackPtr != '\0')
        {
            ++strlen;
            ++trackPtr;
        }

        (*args)[j] = (char*)malloc(sizeof(char) * (strlen + 1));
        copyNChars(startPtr, (*args)[j], strlen);
    }

    return argc;
}

// word counter 
int countW(char *ch)
{
    int state = 0;
    int argc = 0;

    // while the array pointer is not == to the null terminator
    // look for elements that have 2 consecutive non-space characters
    while(*ch != '\0')
    {
        switch(state)
        {
            // if the the element being read is not a space read the character and increase word count by 1 
            // then go to state 1. Else return 0 to state and repeat state 0;
            case 0:
                if(!isspace(*ch))
                {
                    //putchar(*ch);
                    ++argc;
                    state = 1;
                }
            else
            {
                state = 0;
            }
            break;
            // if the count was advanced check to see if the next character is a white space character
            // if it is print the space and return to state 1 continues until a non white space char is read
            case 1:
                if(!isspace(*ch))
                {
                   // putchar(*ch);
                    state = 1;
                }
                else
                {
                    state = 0;
                }
                break;
        }
        ++ch;
    }
    return argc;
}

void copyNChars(char *src, char *dest, int n)
{
    for (int k = 0; k < n; ++k)
    {
        dest[k] = src[k];
    }
    dest[n] = '\0';
}