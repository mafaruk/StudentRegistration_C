#include<stdio.h>
#include"FileInfo.h"
#include<string.h>
#include"AddRecord.h"
#include <stdlib.h>
stud s;
int verification(int rn ){
	char check[10];
	scanf("%s",check);
	if(strcmp(check,"U")==0){
		addRecord(rn);
	}
	else if(strcmp(check,"P")==0){
		return 1;
	}
	else{
		printf("\n\ninvalid Input\nPlease Enter Valid Choice\n");
		verification(rn);
	}
}
int addRecord(int rn){
	s = getStudentStruct(rn);
	printf("\nRoll no: %d\n",s.rollno);
	printf("Name : %s\n",s.name);
	printf("Middle Name : %s\n",s.fname);
	printf("Last Name : %s\n",s.lname);
	printf("Date of Birth : %d-%d-%d\n",s.db.dd,s.db.mm,s.db.yy);
	printf("Address : %s\n",s.add);
	printf("class : %s\n",s.cls);
	printf("\nPress U to update the Information or Press P to proceed\n");
	char sr[100] ={};
	
	if(verification(s.rollno)==1){
		//printf("\nverifyed\n");
		itoa(s.rollno,sr,10);
		char index[350] ={};
		strcpy(index,strcat(strcat(sr,s.name),s.cls));
		int retIdx = getIndexFile(index);
		if (retIdx==0){
			//printf("\nindex modified then added\n");
			char sd[10]={};char sm[10]={};char sy[10]={};
			itoa(s.db.dd,sd,10);itoa(s.db.mm,sm,10);itoa(s.db.yy,sy,10);
			strcpy(index,strcat(strcat(strcat(strcat(sd,"-"),sm),"-"),sy));
			retIdx = getIndexFile(strcat(strcat(strcat(sr,s.name),s.cls),sd));
			if(retIdx==1){
				//printf("\nAdded Successfully\n");
				return setDataFile(&s,index);
			}
			else{
				printf("\n Technical Issue \nContact IT Support \n");
				return 0;
			}
		}
		else if(retIdx==1){
			printf("\nAdded Successfully\n\n");
			return setDataFile(&s,index);
		}
		else{
			return 0;
		}
	}
}