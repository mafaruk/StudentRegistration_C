//#include"Add.c"
typedef struct students {
	char name[100];
	char fname[100];
	char lname[100];
	char dob[100];
	char add[100];
	char cls[100];
	int rollno;	
}stud;
int add_record(int );
int verification();
int add_to_database();
void setName(stud *s);
void setFName(stud *s);
void setLName(stud *s);
void setDob(stud *s);
void setAddress(stud *s);
void setClass(stud *s);




