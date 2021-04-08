#include<stdio.h>
#include"FileInfo.h"
#include"AddRecord.h"
#include"SearchRecord.h"
#include"DeleteRecord.h"
#include"UpdateRecord.h"
void home(){
	printf("Options\n\n\n1.Add \n2.Search \n3.Delete \n4.Update\n ");
	int choice;
	int rollno;
	printf("\nPlease Enter The Number Of Your Choice\n\n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			rollno = getRollNofile();
			if(rollno==1){
				setIndexFile();
			}
			addRecord(rollno);
			rollno++;
			setRollNofile(rollno);
			home();
			break;
		case 2:
			searchRecord();
			home();
			break;
		case 3:
			deleteRecord();
			home();
			break;
		case 4:
			updateRecord();
			home();
			break;
		case 5:
			break;
		default: 
			break;
	}
}
	
int main(){
	printf("Welcome \n\n");
	
	home();
	
}