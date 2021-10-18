#pragma once
#include "definitions.h"
void printStudent(type_student student);
void printStudents(type_student students[], int noStudents);
void printEminentStudents(type_student students[], int noStudents);
void printStudentsReverse(type_student students[], int noStudents);
void printStudentsByAbsences(type_student students[], int noStudents);
void printStudentsByGPA(type_student students[], int noStudents, bool promoted);
void printStudentsByFailedExams(type_student students[], int noStudents);
void printListofStudents(type_student students[], int noStudents);
void printSpecificStudent(type_student students[], int noStudents);
void printStudentOptions();
void printStudentsByGPAalphabetical(type_student students[], int noStudents, bool promoted);