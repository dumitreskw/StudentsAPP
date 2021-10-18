#pragma once
#include "definitions.h"

float getGradesAVG(int grades[]);
float getHighestGPA(type_student students[], int noStudents);
type_student getStudent(type_student students[], int noStudents, char firstname[], char lastname[]);
float getLowestGPA(type_student students[], int noStudents);
int getFailedExams(type_student student);