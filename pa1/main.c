#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
// int isKeyword(char buffer[]){
// 	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
// 							"do","double","else","enum","extern","float","for","goto",
// 							"if","int","long","register","return","short","signed",
// 							"sizeof","static","struct","switch","typedef","union",
// 							"unsigned","void","volatile","while"};
// 	int i, flag = 0;
	
// 	for(i = 0; i < 32; ++i){
// 		if(strcmp(keywords[i], buffer) == 0){
// 			flag = 1;
// 			break;
// 		}
// 	}
	
// 	return flag;
// }
 
int main(){
	char ch, buffer[15], operators[] = "+-*/%=", fName, uIn[255];
	FILE *fp;
	int i,j=0;
	
    // printf("Please enter a file name: ");
    // fName = scanf("%s",uIn);

	fp = fopen("hello_world","r");
	
	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}
	
	while((ch = fgetc(fp)) != EOF)
    {

   		
   		if(isalnum(ch))
        {
   			buffer[j++] = ch;
   		}

        for(i = 0; i < 6; ++i)
        {
   			if(ch == operators[i])
   				printf("%c\n", ch);
   		}
        
   		if((ch == ' ' || ch == '_' || ch == '\n') && (j != 0))
           {
   				buffer[j] = '\0';
   				j = 0;
   				   				
   				// if(isKeyword(buffer) == 1)
   				// 	printf("%s is keyword\n", buffer);

   					printf("%s\n", buffer);
   		}
   		
	}
	
	fclose(fp);
	
	return 0;
}