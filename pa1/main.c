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

extern int errno;

int main(int argc, char **argv)
{

    int fd = open("hello_world.ccx", O_RDONLY | O_CREAT);

    printf("fd = %d\n", fd);

    if (fd == -1)
    {
        printf("Error %d\n", errno);

        perror("Program");
    }

    return 0;
}