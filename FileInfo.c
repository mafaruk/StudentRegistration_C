#include<stdio.h>
#include<string.h>
#include"FileInfo.h"
#include <sys/stat.h>   // stat
#include <stdbool.h>    // bool type

bool file_exists(char *filename) {
  struct stat   buffer;   
  return (stat  (filename, &buffer) == 0);
}
int getNlines(){
	FILE *fp;
	fp = fopen("database/index.txt","r");
	char c; int count = 0;
	while((c=fgetc(fp))!=EOF)
	{
		if(c=='\n')
			count++;
	}
	fclose(fp);
	return count;
}

void setIndexFile(){
	FILE *fp;
	fp = fopen("database/index.txt","a");
	fputs("0nameCL01-01-0101 \n",fp);
	fclose(fp);
}

int getIndexFile(char *keyword){
	
//	printf("\nin getIndexFile\n");
	FILE *fp;
	fp = fopen("database/index.txt","ra+");
	char name[100];
	int i = 0;
	while(fscanf(fp, "%s",name) != EOF)
    {
	//	printf("\n file is not empty\n");
		//printf("%s == %s ",keyword,name);
		if(strlen(name)==strlen(keyword)){
			if(strcmp(keyword,name)==0){
				printf("%s",name);
				i = 1;
			}
			else{
				i = 0;
			}
		}		 
	}
	if(i==0){
		char act_index[100];
		strcpy(act_index,keyword);
		fputs(strcat(act_index,"\n"),fp);
		fclose(fp);
		return 1;
	}
	else{
		fclose(fp);
		return 0;
	}
	
}

int setDataFile(stud *s1, char *fileName){
	char path[1000]={};
	//printf("%s",fileName);
	strcat(strcat(strcat(path,"database/"),fileName),".txt");
	//printf("%s",path);
	FILE *fp;
	fp = fopen(path,"ab+");
	fwrite(s1,sizeof(s1),100,fp);
	fclose(fp); 
	return 1;
}

int getRollNofile(){
	int rollno;
	FILE *fp;
	fp = fopen("database/rollno.txt","rw");
	fscanf(fp, "%d",&rollno);
	fclose(fp);
	return rollno;
}

void setRollNofile(int rollno){
	FILE *fp;
	fp = fopen("database/rollno.txt","rw+");
	fprintf(fp,"%d",rollno);
	fclose(fp);
}

int getDataFile(stud *s1,char *srch_key){
	FILE *fp1;
	char path[100]={};
	strcat(strcat(strcat(path,"database/"),srch_key),".txt");
	fp1 = fopen(path,"r");
	if(file_exists(path)){
		fread(s1,sizeof(s1),100,fp1);
		fclose(fp1);
		return 1;
	}
	else{
		strcat(srch_key,"\t Not found ");
		fclose(fp1);
		return 0;
	}
}

int setBackUpIndexFile(char *del_key){
	FILE *fp;
	fp = fopen("database/backup/index_backup.txt","ab+");
	char act_index[100];
	strcpy(act_index,del_key);
	//printf("in setBackUpIndexFile file name %s.txt \n",act_index);
	fputs(strcat(act_index,"\n"),fp);
	fclose(fp);
	return 1;
}

int setBackUpDataFile(stud *s2,char *del_key){
	char temp_del[100]={};
	strcat(strcat(temp_del,"backup/"),del_key);
	//printf("in setBackUpDataFile file name %s.txt \n",temp_del);
	return setDataFile(s2,temp_del);
}

int deleteDateFile(stud *s1,char *del_key){
	int del = 1; 
	int bu = setBackUpIndexFile(del_key);
	if(bu == 1){
		int dfbu = setBackUpDataFile(s1,del_key);
		if(dfbu==1){
			if(deleteIndex(del_key)==1){
				char del_fname[100] = {};
				strcat(strcat(strcat(del_fname,"database/"),del_key),".txt");
				printf("\n\n");	
				del = remove(del_fname);
				return del;
			}
		}
		else{
			return del;
		}
	}
	else{
		return del;
	}
	
}

int deleteIndex(char *keyword){
	FILE *fpr,*fp;
	fpr = fopen("database/Index.txt","rw");
	int i=0;
	//printf("%s",keyword);
	int ln = getNlines();
	char index[ln][100];
	char name[100]={};
	while(fscanf(fpr, "%s",name) != EOF)
    {
        if(strcmp(name,keyword)==0){
			strcpy(index[i]," ");
			//printf("\nName := %s",index[i]);
			//printf("\n := %d",i);
			i++;
		}
		else{
			strcpy(index[i],name);
			i++;
		}
	}
	fclose(fpr);
	remove("database/Index.txt");
	fp = fopen("database/Index.txt","ab+");
	int j =0;
	while(i!=j){
		//printf("\nName := %s\n",index[j]);
		fputs(strcat(index[j],"\n"),fp);
		j++;
	}
	fclose(fp);
	return 1;
}

// char** getAllIndices(){
	// FILE *fpr;
	// fpr = fopen("database/Index.txt","r");
	// int i=0;
	// char *index[getNlines()];
	// char name[100]={};
	// while(fscanf(fpr, "%s",name) != EOF)
    // {
		// strcpy(index[i],name);
		// i++;
	// }
	// return index;
// } 
 
