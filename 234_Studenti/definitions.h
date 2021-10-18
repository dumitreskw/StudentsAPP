#pragma once
#define MAXSTUDENTS 100
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct {
	char city_name[15];
	char street[25];
	int city_id;
	int number;
}type_address;

typedef struct {
	int prefix;
	long long number;
}type_telephone;

typedef struct {
	char lastname[20];
	char firstname[20];
}type_identity;

typedef struct {
	type_identity identity;
	type_address address;
	type_telephone telephone;
	char faculty[3];
	int age;
	int grades[10];
	float gradesAVG;
	int no_absences;
}type_student;

