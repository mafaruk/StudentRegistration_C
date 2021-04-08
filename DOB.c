#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"DOB.h"
dob d;
static int t_d = 0;
static int t_m = 0;
static int t_y = 0;
void setYear(int y){
	t_y = y;
	if((getYear()<=1900) || getYear()>=2020){
		printf("Invalid Year\n");
		printf("Enter Year: ");
		scanf("%d",&y);	
		setYear(y);
	}
}

void setMonth(int m){
	t_m = m;
	if((getMonth()>=1) && (getMonth()<=12)){
		int y;
		printf("Enter Year: ");
		scanf("%d",&y);	
		setYear(y);
	}
	else{
		printf("Invalid Month\n");
		printf("Enter Month: ");
		scanf("%d",&m);
		setMonth(m);
	}
}
	
void setDay(int day){
	t_d = day;
	if((getDay()>=1)&&(getDay()<=31)){
		int m;
		printf("Enter Month: ");
		scanf("%d",&m);
		setMonth(m);
	}
	else{
		printf("Invalid Day\n");
		printf("Enter Day: ");
		scanf("%d",&day);
		setDay(day);
	}
}		
int getDay(){
	return t_d;
}

int getMonth(){
	return t_m;
}

int getYear(){
	return t_y;
}

dob getDob(){
	printf("Please Enter Your Date of Birth (dd/yy/mmmm) : \n");
	char sd[10],sm[10],sy[10];
	int d;
	printf("Enter Day: ");
	scanf("%d",&d);
	setDay(d);
	
	dob d1;
	d1.dd = getDay();
	d1.mm = getMonth();
	d1.yy = getYear();
	return d1;
}			
