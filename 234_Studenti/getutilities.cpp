#include "getutilities.h"
#include "definitions.h"
#include <iostream>
float getGradesAVG(int grades[]) {
	float gradesAVG = 0;
	for (int i = 0; i < 10; i++) {
		gradesAVG = gradesAVG + grades[i];
	}
	gradesAVG = gradesAVG / 10;
	return gradesAVG;
}

float getHighestGPA(type_student students[], int noStudents) {
	int i = 0;
	float maxGPA = 0;
	for (i = 0; i < noStudents; i++) {
		maxGPA = max(maxGPA, students[i].gradesAVG);
	}
	return maxGPA;
}

type_student getStudent(type_student students[], int noStudents,char firstname[], char lastname[]) {
	for (int i = 0; i < noStudents; i++) {
		if (strcmp(students[i].identity.firstname, firstname) == 0 && strcmp(students[i].identity.lastname, lastname) == 0) {
			return students[i];
		}
	}
}
float getLowestGPA(type_student students[], int noStudents) {
	int i = 0;
	float minGPA = 0;
	for (i = 0; i < noStudents; i++) {
		minGPA = min(minGPA, students[i].gradesAVG);
	}
	return minGPA;
}

int getFailedExams(type_student student) {
	int i = 0;
	int counter = 0;
	for (i = 0; i < 10; i++) {
		if (student.grades[i] < 5) {
			counter++;
		}
	}
	return counter;
}