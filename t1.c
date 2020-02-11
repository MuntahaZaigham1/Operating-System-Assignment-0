#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include <stdbool.h> 
#include <stdlib.h>
int checkDigit(char w);

int main(int argc,char *arg[] )
{
	if(argc<2){
	 printf("Please enter the file name you want to open \n");
	}
	else{
	
	FILE *read;
	char word;
	char arr[200];
	char file[3];
	file[0]='q';
	file[1]='1';
	file[2]='_';
	
	printf("%s\n",file);
	strcat(arg[1],".txt");
	strcat(file,arg[1]);
	printf("%s\n",file);
	read = fopen(file, "r");
	int count=0;
	if (read == NULL)
    {
        printf("Cannot open file ");
        return 0;
    }
    word = fgetc(read);
	int i=0;
    while (word != EOF)
    {
        if(checkDigit(word)==1){
        count++;
        }
	     
      
        
        
		word = fgetc(read);
        
	}
	printf("The number of digits in the given file are = %d\n",count);
	fclose(read);
	}
    return 0;

}

int checkDigit(char w){
int f=0;
if( w >='0' && w <='9')
{
f=1;

}




return f;

}
