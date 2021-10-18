#include "printings.h"
#include "definitions.h"
#include "getutilities.h"
#include "sorting.h"
#include "utilities.h"
#include <iostream>
void printStudent(type_student student) {
	std::cout << "\n__________________________________________\n";
	std::cout << "Firstname: " << student.identity.firstname << "\n";
	std::cout << "Lastname: " << student.identity.lastname << "\n";
	std::cout << "Age: " << student.age << "\n";
	std::cout << "City: " << student.address.city_name  << " (code: " << student.address.city_id << ")" << "\n";
	std::cout << "Street: " << student.address.street << " " << student.address.number << "\n";
	std::cout << "Phone number: +" << student.telephone.prefix << " " << student.telephone.number << "\n";;
	std::cout << "Faculty code: " << student.faculty << "\n";
	std::cout << "GPA: " << student.gradesAVG << "\n";
	std::cout << "Number of absences: " << student.no_absences << "\n";
	std::cout << "\n__________________________________________\n";
}

void printStudentOptions() {
	std::cout << "\nOPTIONS:\n";
	std::cout << "__________________________________________\n";
	std::cout << "[1]. List students alphabetical.\n";
	std::cout << "[2]. List students by GPA.\n";
	std::cout << "[3]. Go back to main menu.\n";
	std::cout << "Enter your option: ";

}
void printStudents(type_student students[], int noStudents) {
	int i = 0;
	for (i = 0; i < noStudents; i++) {
		std::cout << "\nStudent NO. " << i+1;
		printStudent(students[i]);
	}
}
void printSpecificStudent(type_student students[], int noStudents) {
	int i = 0;
	int option = 0;
	std::cout << "Please input id of the student: ";
	std::cin >> option;
	check(option, 1, noStudents);
	printStudent(students[option - 1]);
}
void printListofStudents(type_student students[], int noStudents) {
	int i = 0;
	for (i = 0; i < noStudents; i++) {
		std::cout << i+1 << ". " << students[i].identity.lastname << " " << students[i].identity.firstname << " " << "GPA: "
			<< students[i].gradesAVG << " Absences: " << students[i].no_absences << " Failed exams: " << getFailedExams(students[i]) << "\n";
	}
}

void printEminentStudents(type_student students[], int noStudents) {
	int i = 0;
	int counter = 0;
	float maxGPA = getHighestGPA(students, noStudents);
	sortAlphabetical(students, noStudents);
	std::cout << maxGPA << "\n";
	if (maxGPA >= 5) {
		std::cout << "Printing most eminent student/students: \n";
		for (i = 0; i < noStudents; i++) {
			if (students[i].gradesAVG == maxGPA) {
				counter++;
				std::cout << counter << ". " << students[i].identity.lastname << " " << students[i].identity.firstname << " " << maxGPA << "\n";
			}
		}
	}
	else {
		std::cout << "There are no eminent students in this group.";
	}

}

void printStudentsReverse(type_student students[], int noStudents) {
	int i = 0;
	for (i = noStudents-1; i >= 0; i--) {
		std::cout << "Student NO. " << i+1 << "\n";
		printStudent(students[i]);
	}
}

void printStudentsByGPA(type_student students[], int noStudents, bool promoted) {
	sortbyGPA(students, noStudents);
	for (int i = 0; i < noStudents; i++) {
		if (students[i].gradesAVG >= 5 && promoted) {
			std::cout << "\n" << i+1 << ". " << students[i].identity.lastname << " " << students[i].identity.firstname << " " << "GPA: "
				<< students[i].gradesAVG << " Absences: " << students[i].no_absences << " Failed exams: " << getFailedExams(students[i]) << "\n";
		}
		if (students[i].gradesAVG < 5 && !promoted) {
			std::cout << "\n" << i+1 << ". " << students[i].identity.lastname << " " << students[i].identity.firstname << " " << "GPA: "
				<< students[i].gradesAVG << " Absences: " << students[i].no_absences << " Failed exams: " << getFailedExams(students[i]) << "\n";
		}
	}
}


void printStudentsByAbsences(type_student students[], int noStudents) {
	sortbyAbsences(students, noStudents);
	printListofStudents(students, noStudents);
}

void printStudentsByFailedExams(type_student students[], int noStudents) {
	sortByFailedExams(students, noStudents);
	printListofStudents(students, noStudents);
}

void printStudentsByGPAalphabetical(type_student students[], int noStudents, bool promoted) {
	sortAlphabetical(students, noStudents);
	for (int i = 0; i < noStudents; i++) {
		if (students[i].gradesAVG >= 5 && promoted) {
			std::cout << "\n" << i+1 << ". " << students[i].identity.lastname << " " << students[i].identity.firstname << " " << "GPA: "
				<< students[i].gradesAVG << " Absences: " << students[i].no_absences << " Failed exams: " << getFailedExams(students[i]) << "\n";
		}
		if (students[i].gradesAVG < 5 && !promoted) {
				std::cout << "\n" << i+1 << ". " << students[i].identity.lastname << " " << students[i].identity.firstname << " " << "GPA: "
					<< students[i].gradesAVG << " Absences: " << students[i].no_absences << " Failed exams: " << getFailedExams(students[i]) << "\n";
		}
	}
}
