#include<stdio.h>
#include<string.h>
int main(){
	char name[100];
	scanf("%s",name);
	FILE *fp;
	fp = fopen("database/Index.txt","ab+");
	fputs(strcat(name,"\n"),fp);
	fclose(fp);
}