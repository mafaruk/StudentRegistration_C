#include<stdio.h>
#include"FileInfo.h"
#include<string.h>
#include <stdlib.h>
#include"AddRecord.h"
#include"SearchRecord.h"
int updateRecord(){
	stud s = searchRecord();
	if(s.rollno!=0){
		//stud s1 = getStudentStruct(s.rollno);
		char sr[100] ={};
		itoa(s.rollno,sr,10);
		char index[350] ={};
		int t_rn = s.rollno;
		strcpy(index,strcat(strcat(sr,s.name),s.cls));
		deleteDateFile(&s,index);
		int i = addRecord(t_rn);	
	}
	
}