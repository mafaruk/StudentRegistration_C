#include"DOB.h"
typedef struct students {
	char name[100];
	char fname[100];
	char lname[100];
	dob db;
	char add[100];
	char cls[100];
	int rollno;	
}stud;

void setName(char *name);
void setFname(char *Fname);
void setLname(char *Lname);
void setAdd(char *add);
void setclass(char *cls);
void setRollno(int rollno);
char *getName();
char *getFName();
char *getLName();
char *getAdd();
char *getClass();
char *getName();
dob getDobs();
int getRollno();
stud getStudentStruct();
stud searchStudent();
