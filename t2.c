#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include <stdbool.h> 
#include <stdlib.h>
//int addRecord(struct student &stud);
struct student
{
 char name[10];
 char rollno[10];
 char email[10];
}stud;

int main(int argc,char *arg[] )
{
	char n;
   
   FILE *rec;
 	rec = fopen("e4.txt", "a");
 	if (rec == NULL)
  		{
        printf("Cannot open the file ");
        
    	}
  	
   //struct student stud;
   
   
    printf(" What do You want to do? \n ");
    printf(" Type '1' to Add a record. \n ");
    printf(" Type '2' to Delete a record. \n ");
    printf(" Type '3' to Search a record. \n ");
    printf(" Type 'q' to Exit. \n ");
    n = getchar( );
   // stdin("%c",&n);
    if(n=='1'){ printf(" 1111\n ");
    printf(" record 1:\n ");
    	addRecord(rec);
    printf(" record 2:\n ");
 		addRecord(rec);
 	 printf(" record 3:\n ");
    	addRecord(rec);
    	fclose(rec);
    }
    else if(n=='2'){ 
    char r[10];
 	printf("Enter  Roll no you want to delete:");
 	scanf("%s",r);
 	deleteRecord(r);
    }
    else if(n=='3'){ 
    char r[10];
 	printf("Enter  Roll no you want to search:");
 	scanf("%s",r);
    searchRecord(r);
    }
    else if(n=='q'){
    	return 0;
    }
    else printf(" Enter valid choice.. \n ");

   
    
    return 0;
    }

    
void addRecord(FILE * rec)
{
 
    	char name[10];
    	char roll[10];
    	char em[10];
 printf("Enter  Roll no:");
 scanf("%s",roll);
 printf("Enter  Name :");
	scanf("%s",name);
 printf("Enter  email-address :");
 scanf("%s",em);
 strcpy(stud.name,name);
 strcpy(stud.rollno,roll);
 strcpy(stud.email,em);
 fprintf(rec,"%s\t",stud.name);
 fprintf(rec,"%s\t",stud.rollno);
 fprintf(rec,"%s\n",stud.email);
 
}
 
void searchRecord(char roll[])
{ 
FILE *fp;
fp = fopen("e4.txt", "r");
    //rewind(fp);
    while(fread(&stud,sizeof(stud),1,fp)){
        if(strstr(stud.rollno,roll)) {
        printf("%s\t%s\t%s\n",stud.name,stud.rollno,stud.email);
        
        }
         
         //printf("%s\t%s\t%s\n",stud.name,stud.rollno,stud.email);
        
 }
 fclose(fp);
 }
int deleteRecord(char r[])
{

 FILE *rec;
 FILE *temp;
 char st[10];
  rec = fopen("e4.txt", "r");
  temp = fopen("Temp.txt", "w");
  while (fread(&stud, sizeof(stud), 1, rec))
  {
   strcpy(st,stud.rollno);
  
   if (!strstr(st,r))
    fwrite(&stud, sizeof(stud), 1, temp);
    
   
  }
  fclose(rec);
  fclose(temp);
  rec = fopen("e4.txt", "w");
  temp = fopen("Temp.txt", "r");
  while (fread(&stud, sizeof(stud), 1, temp))
   fwrite(&stud, sizeof(stud), 1, rec);
  printf("\nRecord is deleted\n");
  fclose(rec);
  fclose(temp);
 
 
}
   
    
