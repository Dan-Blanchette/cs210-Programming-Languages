#include <stdio.h>
#include <stdlib.h>

char* removeComments(char *ccx);

int main(int argc, char **argv)
{

    return 0;
}

char* removeComments(char *ccx)
{
    char *noComments = malloc(sizeof(char) * strlen(ccx));
    noComments[0] = '\0';

    int inComment = 0;

    for (int i = 0; i < strlen(ccx); ++i)
    {
        if (ccx[i] == '/' && ccx[i + 1] == '*')
        {
            inComment = 1;
            i += 2;
        }
        else if (ccx[i] == '*' && ccx[i + 1] == '/')
        {
            inComment = 0;
            i += 2;
        }

        if (!inComment)
        {
            strncat(noComments, &(ccx[i]), 1);
        }
    }
    return noComments;
}