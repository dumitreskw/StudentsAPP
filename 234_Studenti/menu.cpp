#include "menu.h"
#include "definitions.h"
#include "readings.h"
#include "printings.h"
#include "utilities.h"
#include "sorting.h"
#include <iostream>

void showMenu() {
	std::cout << "MENU\n";
	std::cout << "________________________\n";
	std::cout << "[1]. Add students in a group.\n";
	std::cout << "[1]. Show students in group.\n";
	std::cout << "[3]. Show all data from a student.\n";
	std::cout << "[4]. Delete student from group.\n";
	std::cout << "[5]. Show most eminent student/students.\n";
	std::cout << "[6]. Show students by the number of failed exams.\n";
	std::cout << "[7]. Show students by the number of absences.\n";
	std::cout << "[8]. Show promoted students.\n";
	std::cout << "[9]. Show failed students.\n";
	std::cout << "[0]. EXIT.\n";
	std::cout << "Enter your option: ";
}

void startProgram() {
	int noStudents = 0;
	int option = 1, studOption;
	type_student* students = new(std::nothrow) type_student[MAXSTUDENTS];

	while (option != 0) {
		showMenu();
		std::cin >> option;
		check(option, 0, 9);
		switch (option) {
		case 1:
			readGroupOfStudents(students, noStudents);
			break;
		case 2:
			printListofStudents(students, noStudents);
			break;
		case 3:
			printSpecificStudent(students, noStudents);
			break;
		case 4:
			deleteStudent(students, noStudents);
			break;
		case 5:
			printEminentStudents(students, noStudents);
			break;
		case 6:
			printStudentsByFailedExams(students, noStudents);
			break;
		case 7:
			printStudentsByAbsences(students, noStudents);
			break;
		case 8:
			printStudentOptions();
			std::cin >> studOption;
			check(studOption, 1, 3);
			if (studOption == 1) {
				printStudentsByGPAalphabetical(students, noStudents, true);
			}
			if (studOption == 2) {
				printStudentsByGPA(students, noStudents, true);
			}
			break;
		case 9:
			printStudentOptions();
			std::cin >> studOption;
			check(studOption, 1, 3);
			if (studOption == 1) {
				printStudentsByGPAalphabetical(students, noStudents, false);
			}
			if (studOption == 2) {
				printStudentsByGPA(students, noStudents, false);
			}
			break;
		}
	}
}

