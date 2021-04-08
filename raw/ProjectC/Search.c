#include<stdio.h>
#include<string.h>
#include"Search.h"

int getNlines(){
	FILE *fp;
	fp = fopen("database/Index.txt","r");
	char c; int count = 0;
	while((c=fgetc(fp))!=EOF)
	{
		if(c=='\n')
			count++;
	}
	fclose(fp);
	return count;
}
int search(char *name, char *lname,char *cls,char *rno){
	// printf("Name: %s\n",name);
	// printf("Class : %s\n",cls);
	// printf("date of birth: %s\n",dob);
	char keyword[100] ={};
	strcat(strcat(strcat(strcat(keyword,rno),name),lname),cls);
	char *File = getIndex(keyword);
}
char *getIndex(char *keyword){
	//printf("\nName := %s",keyword);
	FILE *fpr,*fp;
	fpr = fopen("database/Index.txt","r");
	//printf("\nName := %f",sizeof(*fpr)*4);
	int i=0;
	printf("%s",keyword);
	char index[getNlines()][100];
	char name[100]={};
	while(fscanf(fpr, "%s",name) != EOF)
    {
        if(strcmp(name,keyword)>=0){
			if(strcmp(name,keyword)==0){
				strcpy(index[i],name);
				printf("\nName := %s",index[i]);
				//printf("\n := %d",i);
				i++;
				break;
			}
		}
		else{
			strcpy(index[i],name);
			printf("\nName := %s",index[i]);
			//printf("\n := %d",i);
			i++; 
		}
	}
	
}

// fred = fopen(path,"ab+");
	// while(fread(&n,sizeof(s),1,fprec)==1)
        // {
            // printf("\nID := %d",n.rollno);
            // printf("\nName := %s",n.name);
            // // flushall();
            // // printf("\nSalary:= %f",s.sal);
            // printf("\n********************\n");
        // }
	// fclose(fred);