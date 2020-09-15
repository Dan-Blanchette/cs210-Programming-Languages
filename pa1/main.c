/* Dan Blanchette
 * cs210 
 * Dr. Rinker
 * ( program start date: 14, sept 2020)
 * 
 * This program will identify and seperate all possible "words" 
 * as tokens from within a CCX code file. It will ignore all 
 * comment lines from the program.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    FILE *fd;
    char fc[BUFFER_SIZE];
    int totalRead = 0;

    fd = fopen("hello_world.ccx", "r");

    if(fopen == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please ensure file exits\n");
        exit(EXIT_FAILURE);
    }

    printf("File opened, Reading file contents\n");

    while ( fgets(fc, BUFFER_SIZE, fd) != NULL )
    {
        totalRead = strlen(fc);

        fc[totalRead - 1] =  fc[totalRead - 1] = '\n' ? '\0' : fc[totalRead - 1];

        printf("%s\n", fc);
    }

    fclose(fd);

    return 0;
}