#include <stdio.h>
int main()
{
    /* Pointer to the file */
    FILE *fp1;
    /* Character variable to read the content of file */
    char c, fileName[100];
    
    printf("Please enter a file name:");
    scanf("%s", fileName);
    // get command line input for file name.

    /* Opening a file in r mode*/
     fp1= fopen (fileName, "r");

     /* Infinite loop –I have used break to come out of the loop*/
     while(1)
     {
        c = fgetc(fp1);
        if(c==EOF)
        {
            printf("\n");
            break;
        }

        else
            printf("%c", c);
     }
     fclose(fp1);
     return 0;
}