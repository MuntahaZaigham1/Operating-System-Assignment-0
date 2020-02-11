#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include <stdbool.h> 
#include <stdlib.h>
bool checkvowel(char arr[]);
int main(int argc,char *arg[] )
{
	if(argc<2){
	 printf("Please enter the file name you want to open \n");
	}
	else{      
    FILE *read;
    FILE *write;
    char file[3];
	file[0]='q';
	file[1]='3';
	file[2]='_';
	strcat(arg[1],".txt");
	strcat(file,arg[1]);
    read = fopen(file, "r");
    write = fopen("output.txt", "w");
     if (read == NULL)
    {
        printf("Cannot open input file ");
        return 0;
    }
	if (write == NULL)
    {
        printf("Cannot open output file ");
        return 0;
    }
    
    char word;
    char c;
    int count;
    
    
    bool flag;
    flag=false;
    
    //word = fgetc(read);
	int i=0;
	int si;
	int chars;
	char arr[100];
	
	
	while( fscanf(read, "%s", arr) != EOF )
        {
      
        flag=checkvowel(arr);
       
         if(flag==true){
        	//writeback without reversing
        	int chars=fprintf(write,arr);
        	fputc(' ',write);
        }
        else{
        int m=0,n=0;
			char o;
			while(arr[m]!='\0'){
			m++;
			}
			int end =m-1;
			for (n= 0; n < m/2; n++) {
				o        = arr[n];
				arr[n]   = arr[end];
				arr[end] = o;
			 
				end--;
			  }
			 int chars= fprintf(write,arr);
        	fputc(' ',write);
        
        }
            
        }
        
	
        
        
    
    
    
       fclose(read);
    fclose(write); 
    }



return 0;

}

bool checkvowel(char arr[]){
int i=0;
//printf("%d",strlen(arr));
while(i!=strlen(arr)){
if( (arr[i]=='a' ||arr[i]=='A') || (arr[i]=='e' ||arr[i]=='E')|| (arr[i]=='i' ||arr[i]=='I') || (arr[i]=='o' ||arr[i]=='O') || (arr[i]=='u' ||arr[i]=='U'))
{
return true;
}
i++;


}
return false; 

}

