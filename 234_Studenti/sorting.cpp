#include "sorting.h"
#include "utilities.h"
#include "getutilities.h"
#include <string>
void sortbyGPA(type_student students[], int noStudents) {
	int i = 0, j = 0;
	for (i = 0; i < noStudents - 1; i++) {
		for (j = i + 1; j < noStudents; j++) {
			if (students[i].gradesAVG < students[j].gradesAVG)
				swap(students[i], students[j]);
		}
	}
}

void sortbyAbsences(type_student students[], int noStudents) {
	int i = 0, j = 0;
	for (i = 0; i < noStudents - 1; i++) {
		for (j = i + 1; j < noStudents; j++) {
			if (students[i].no_absences < students[j].no_absences)
				swap(students[i], students[j]);
		}
	}
}

void sortAlphabetical(type_student students[], int noStudents) {
	int i = 0, j = 0;
	for (i = 0; i < noStudents - 1; i++) {
		for (j = i + 1; j < noStudents; j++) {
			if (strcmp(students[i].identity.lastname,students[j].identity.lastname) <= 0 && 
						strcmp(students[i].identity.firstname, students[j].identity.firstname) < 0)
				swap(students[i], students[j]);
		}
	}
}

void sortByFailedExams(type_student students[], int noStudents) {
	int i = 0, j = 0;
	for (i = 0; i < noStudents - 1; i++) {
		for (j = i + 1; j < noStudents; j++) {
			if (getFailedExams(students[i]) < getFailedExams(students[j])) {
				swap(students[i], students[j]);
			}
		}
	}
}
