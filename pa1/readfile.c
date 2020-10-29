// #include<stdio.h>
// #include<stdlib.


// int main()
// {
//     /* Pointer to the file */
//     FILE *fp1;
//     /* Character variable to read the content of file */
//     char cj, fileName[100];
    
//     printf("\nPlease enter a file name:");
//     scanf("%s", fileName);
//     // get command line input for file name.

//     /* Opening a file in r mode*/
//      fp1= fopen (fileName, "r");

//      /* Infinite loop –I have used break to come out of the loop*/
//      while(1)
//      {
//         c = fgetc(fp1);
//         if(c==EOF)
//         {
//             printf("\n");
//             break;
//         }
    
//         switch(c)
//         {
//             case '/':
//             if( c == '/' + '*' && c == '*' + '/')
//             break;

//             case '(':
//             printf("%c\n", c);
//             break;

//             default:
//         }





     
//      fclose(fp1);
//      return 0;
// }

// char* removeComments(char *ccx)
// {
//     char *noComments = malloc(sizeof(char) * strlen(ccx));
//     noComments[0] = '\0';

//     int inComment = 0;

//     for (int i = 0; i < strlen(ccx); ++i)
//     {
//         if (ccx[i] == '/' && ccx[i + 1] == '*')
//         {
//             inComment = 1;
//             i += 2;
//         }
//         else if (ccx[i] == '*' && ccx[i + 1] == '/')
//         {
//             inComment = 0;
//             i += 2;
//         }

//         if (!inComment)
//         {
//             strncat(noComments, &(ccx[i]), 1);
//         }
//     }
//     return noComments;
// }