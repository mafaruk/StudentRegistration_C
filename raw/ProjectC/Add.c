#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"Add.h"
stud s;

int add_record(int rollno){
	printf("Please Enter infornmation below \n\n");
	setName(&s);
	setFName(&s);
	setLName(&s);
	setDob(&s);
	setAddress(&s);
	setClass(&s);
	printf("Please verify information\n\n");
	s.rollno = rollno;
	printf("Roll no: %d\n",s.rollno);
	printf("Name : %s\n",s.name);
	printf("Middle Name : %s\n",s.fname);
	printf("Last Name : %s\n",s.lname);
	printf("Date of Birth : %s\n",s.dob);
	printf("Address : %s\n",s.add);
	printf("class : %s\n",s.cls);
	verification(); 
}
void setName(stud *s){
	printf("Please Enter Your Name : ");
	scanf("%s[^\n]",s->name);
}

void setFName(stud *s){
	printf("Please Enter Your Middle Name : ");
	scanf("%s[^\n]",s->fname);
}

void setLName(stud *s){
	printf("Please Enter Your Last Name : ");
	scanf("%s[^\n]",s->lname);
}
	

void setAddress(stud *s){
	printf("Please Enter Your address : ");
	scanf("%s[^\n]",s->add);
}

void setClass(stud *s){
	printf("Please Enter Your class : ");
	scanf("%s[^\n]",s->cls);
}

int add_to_database(){
	FILE *fpi,*fprec;
	char index[100]={};
	char rno[100];
	itoa(s.rollno, rno,100);
	strcat(strcat(strcat(strcat(strcat(index,rno),s.name),s.dob),s.cls),"\n");
	fpi = fopen("database/Index.txt","a");
	fputs(index,fpi);
	fclose(fpi);
	
	char path[100]={};
	strcat(strcat(strcat(strcat(strcat(strcat(path,"database/"),rno),s.name),s.dob),s.cls),".txt");
	//printf("%s",path);
	fprec = fopen(path,"a");
	//1printf("%d",sizeof(s));
	fwrite(&s,sizeof(s),1,fprec);
	fclose(fprec); 
	
}

int verification(){
	printf("Press U to update the Information or Press P to proceed\n");
	char check[10];
	scanf("%s",check);

	if(strcmp(check,"U")==0){
		
		add_record(s.rollno);
	}
	else if(strcmp(check,"P")==0){
		//return 1;
		if(add_to_database()==0){
			return 1;
		}
		
	}
	else{
		printf("\n\ninvalid Input\nPlease valid choice");
		verification();
	}
}
