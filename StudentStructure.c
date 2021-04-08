#include<stdio.h>
#include<string.h>
#include"StudentStructure.h"
static char t_name[100] = {}; 
static char t_fname[100] = {}; 
static char t_lname[100] = {}; 
static char t_add[250] = {}; 
static char t_cls[50] = {};
static int t_rollno;
void setName(char *name){
	strcpy(t_name,name);
}
void setFname(char *fname){
	strcpy(t_fname,fname);	
}
void setLname(char *lname){
	strcpy(t_lname,lname);
}
void setAdd(char *add){
	strcpy(t_add,add);
}
void setclass(char *cls){
	strcpy(t_cls,cls);
}
void setRollno(int rn){
	t_rollno = rn;
}
char *getName(){
	return t_name;
}
char *getFName(){
	return t_fname;
}
char *getLName(){
	return t_lname;
}
char *getAdd(){
	return t_add;
}
char *getClass(){
	return t_cls;
}
int getRollno(){
	return t_rollno;
}
stud s;
stud getStudentStruct(int roll){
	char name[100]={}; 
	char fname[100] = {}; 
	char lname[100] = {}; 
	char add[250] = {}; 
	char cls[50] = {};
	dob db;
	
	printf("Please Enter Your Name : ");
	scanf("%s",name);
	setName(name);
	strcpy(s.name,getName());
	
	printf("Please Enter Your Middle Name : ");
	scanf("%s",fname);
	setFname(fname);
	strcpy(s.fname,getFName());
	
	printf("Please Enter Your Last Name : ");
	scanf("%s",lname);
	setLname(lname);
	strcpy(s.lname,getLName());

	s.db = getDob();
	
	printf("Please Enter Your Adreess : ");
	scanf("%s",add);
	setAdd(add);
	strcpy(s.add,getAdd());

	printf("Please Enter Your Class: ");
	scanf("%s",cls);
	setclass(cls);
	strcpy(s.cls,getClass());
	
	setRollno(roll);
	s.rollno = getRollno();	
	
	return s;
}


stud searchStudent(){
	char name[100] = {}; 
	char cls[50] = {};
	int rn;
	stud s1;
	strcpy(s1.fname,"");
	strcpy(s1.lname,"");
	strcpy(s1.add,"");
	s1.db.dd = 0;
	s1.db.mm = 0;
	s1.db.yy = 0;
	printf("Please Enter Your Name : ");
	scanf("%s",name);
	setName(name);
	strcpy(s1.name,getName());
	
	printf("Please Enter Your Class: ");
	scanf("%s",cls);
	setclass(cls);
	strcpy(s1.cls,getClass());
	
	printf("Please Enter Your Roll No.: ");
	scanf("%d",&rn);
	setRollno(rn);
	s1.rollno = getRollno();	
	
	return s1;
}