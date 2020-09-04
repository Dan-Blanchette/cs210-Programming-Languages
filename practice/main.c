#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Code Credit for the structure of a file read program
// https://codeforwin.org/2018/01/c-program-read-and-display-file-contents.html
#define BUFFER_SIZE 1024

int main()
{
    // Create a file pointer to reference
    // The file

    FILE *fd;
    char fc[BUFFER_SIZE];
    int totalRead = 0;

    // open text.txt and read only
    fd = fopen("text.txt","r"); 
    if(fd == NULL)
    {
        printf("Unable to open File.\n");
        printf("Please check whether file exists\n");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully. Reading file contents\n");

    while(fgets(fc, BUFFER_SIZE, fd) != NULL)
    {
        /* This will calculate the total charcters to be read */
        totalRead = strlen(fc);

        fc[totalRead - 1] = fc[totalRead - 1] 
        == '\n' ? '\0' : fc[totalRead - 1];

        printf("%s\n", fc);
    }

    fclose(fd);
    return 0;
}