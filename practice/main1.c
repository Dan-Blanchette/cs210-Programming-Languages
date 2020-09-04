#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    // file pointer to the start of the file
    FILE *fPtr; 
    // set a value of 1024 bytes not to be modified.
    const int SIZE = 1024;
    // char array pointer serves as the string buffer with a SIZE limit for the buffer 0 - 1023
    char buffer[SIZE]; 
    
    // initialize a read length variable to 0. This will be used to prevent the file pointer from
    // exceeding the buffer size.
    int totalRead = 0;

    // line 14 of the code assigns the file pointer to the start of the file
    // and tells the computer that this will be read only [contents cannot be modified directly]
    fPtr = fopen("text.txt", "r");

    // next we need to create an if statement to ensure that the file was opened.
    // as a means of error checking.
    if(fPtr == NULL)
    {   
        // print out some error messages to help with debugging the file to be opened.
        printf("Error file was not found or could not be read\n");
        printf("Check to see if file exists and try agian\n");
        // create an exit state for when a file fails
        exit(EXIT_FAILURE);    
    }

    // Other wise make display a statement indicating the file opened without issue
    printf("The file was opened successfully now importing its contents: \n");

    // Now we need to get the file's contents into the buffer array so that we can print it out to the terminal.
    // A good place to start is with a while loop where we will use fgets() [ file get string ] to bring the strings
    // present in the file and add them into the buffer.

    // fgets() has the following parameters that must be passed fgets( the file pointer, the buffer size, the array pointer)
    /* followed by the condition that so long as the file pointer has not encountered the null terminator '\0' it will continue to
        to add characters from the string. */

    while(fgets( fPtr, SIZE, buffer ) != NULL)
    {
        /* inside the loop we are now going to ensure that what is printed is all the character strings
         and remove the newline character should it be present in the text file */

        /* This will calculate the total charcters to be read */
        totalRead = strlen(buffer);

        // this is a ternary statement.
        /* from left to right it is evaluated as: buffer[ totalRead - 1] will store the results of
        buffer [totalRead - 1] being equal to a '\n' character T/F. If False it is not a '\n' the it will 
        evaluate if it is a '\0' T/F. While it is still false then it will continue to hold its current value. */

        /* In lame man's terms if buffer[totalRead -1 ] is equal to the '\n' character store that charcter in the buffer.
        if buffer[totalRead -1 ] != '\n' but  == to '\0' Then store that charcter also into the buffer array and terminate the while loop 
        as NULL == '/0' is the terminal condition. 
        Otherwise, continue reading and storing all wide space and chars. */

        buffer[totalRead - 1] = buffer[totalRead - 1] == '\n' ? '\0' : buffer[totalRead - 1]; // Ternary statment.

        // now print what is in the file with printf statement utilizing the buffer and the %s string conversion charcter
        printf("%s\n",buffer);
    } 
    return 0; 
}