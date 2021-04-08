#include"FileInfo.h"
#include"SearchRecord.h"
#include<string.h>
#include <stdlib.h>
#include<stdio.h>
void deleteRecord(){
	stud s = searchRecord();
	char sr[100] ={};
	itoa(s.rollno,sr,10);
	char index[350] ={};
	strcpy(index,strcat(strcat(sr,s.name),s.cls));
	if (!deleteDateFile(&s,index))
      printf("The file is Deleted successfully\n");
	else
      printf("the file is not Deleted\n");
}