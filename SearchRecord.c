#include<stdio.h>
#include"FileInfo.h"
#include<string.h>
#include <stdlib.h>
int confirmation(){
	printf("\nPress Y To Proceed\n\n");
	char check[10];
	scanf("%s",check);
	if(strcmp(check,"Y")==0){
		return 1;
	}
	else{
		printf("\n\ninvalid Input\n\n");
		confirmation();
	}
}
stud searchRecord(){
	stud s,s1;
	s = searchStudent();
	char sr[100] ={};
	itoa(s.rollno,sr,10);
	char index[350] ={};
	strcpy(index,strcat(strcat(sr,s.name),s.cls));
	int exsist;
	if(confirmation()==1){
		exsist = getDataFile(&s1,index);
	}
	if(exsist==1){
		printf("\nRoll no: %d\n",s1.rollno);
		printf("Name : %s\n",s1.name);
		printf("Middle Name : %s\n",s1.fname);
		printf("Last Name : %s\n",s1.lname);
		printf("Date of Birth : %d-%d-%d\n",s1.db.dd,s1.db.mm,s1.db.yy);
		printf("Address : %s\n",s1.add);
		printf("class : %s\n",s1.cls);
		return s1;
	}
	else{
		printf("\nNot Found\n");
		s1.rollno = 0;
		return s1;
	}
}
