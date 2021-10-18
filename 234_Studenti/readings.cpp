#include "definitions.h"
#include "readings.h"
#include "getutilities.h"
#include "utilities.h"
#include <iostream>


void readAddress(type_address& address) {
	std::cout << "Enter city name: ";
	std::cin >> address.city_name;
	std::cout << "Enter street name: ";
	std::cin >> address.street;
	std::cout << "Enter street number: ";
	std::cin >> address.number;
	std::cout << "Enter city id: ";
	std::cin >> address.city_id;
}

void readIdentity(type_identity& identity) {
	std::cout << "Enter firstname: ";
	std::cin >> identity.firstname;
	std::cout << "Enter lastname: ";
	std::cin >> identity.lastname;

}

void readTelephone(type_telephone& telephone) {
	std::cout << "Enter prefix:";
	std::cin >> telephone.prefix;
	std::cout << "Enter number:";
	std::cin >> telephone.number;
}
void readGrades(int grades[]) {
	std::cout << "Enter the 10 grades: \n";
	for (int i = 0; i < 10; i++) {
		std::cout << "[" << i << "]: ";
		std::cin >> grades[i];
		check(grades[i], 1, 10);
	}
}

void readStudent(type_student& student) {
	readIdentity(student.identity);
	readAddress(student.address);
	readTelephone(student.telephone);
	std::cout << "Enter faculty code:";
	std::cin >> student.faculty;
	std::cout << "Enter student's age: ";
	std::cin >> student.age;
	readGrades(student.grades);
	std::cout << "Enter the number of absences: ";
	std::cin >> student.no_absences;
	student.gradesAVG = getGradesAVG(student.grades);
}

void readGroupOfStudents(type_student students[], int &noStudents) {
	int OK = 1; 

	while(OK==1){
		std::cout << "Doriti sa adaugati un nou student? ([0].NU | [1].DA):\n";
		std::cin >> OK;
		check(OK, 0, 1);
		if (OK == 0)
			break;
		if (noStudents < MAXSTUDENTS)
			readStudent(students[noStudents++]);
		else {
			std::cout << "ERROR! Memory allocation failed!";
			break;
		}
	}
}

