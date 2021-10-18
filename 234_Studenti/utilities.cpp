#include "utilities.h"
#include "getutilities.h"
#include <iostream>
void check(int& checkNumber, int MIN, int MAX) {
	while (checkNumber > MAX || checkNumber < MIN) {
		std::cout << "ERROR! Please input a value from " << MIN << " to " << MAX << ": ";
		std::cin >> checkNumber;
	}
}

void swap(type_student& x, type_student& y) {
	type_student temp;
	temp = x;
	x = y;
	y = temp;
}

void deleteStudent(type_student students[], int &noStudents) {
	char firstname[20], lastname[20];
	int i = 0;
	bool deleted = false;
	type_student searchedStudent;
	std::cout << "Enter firstname and lastname of student: ";
	std::cin >> firstname >> lastname;
	searchedStudent = getStudent(students, noStudents, firstname, lastname);
	for (i = 0; i < noStudents; i++) {
		if (strcmp(students[i].identity.firstname, searchedStudent.identity.firstname) == 0 && strcmp(students[i].identity.lastname, searchedStudent.identity.lastname)==0) {
			for (int j = i; j < noStudents-1; j++) {
				swap(students[j], students[j + 1]);
			}
			delete &students[noStudents - 1];
			noStudents--;
			deleted = true;
			break;
		}
	}
	if (!deleted)
		std::cout << "Student wasn't found in group.\n";
}