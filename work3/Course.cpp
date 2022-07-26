#define _CRT_SECURE_NO_WARNINGS
#include "Course.h"

Course::Course()
{
	name = NULL;
	lecturer = NULL;
	grade = 0;
}

Course::Course(char* N, char* L, int G)
{
	name = new char[strlen(N) + 1];
	if (!name)
		exit(1);
	strcpy(name, N);
	lecturer = new char[strlen(L) + 1];
	if (!lecturer)
		exit(1);
	strcpy(lecturer, L);
	grade = G;
}
Course::Course(const Course& C)
{
	name = new char[strlen(C.name) + 1];
	if (!name)
		exit(1);
	strcpy(name,C.name);
	lecturer = new char[strlen(C.lecturer) + 1];
	if (!lecturer)
		exit(1);
	strcpy(lecturer, C.lecturer);
	grade = C.grade;
}

int Course::get_grade()
{
	return grade;
}

void Course::print() const
{
	cout << "the name of course is :" << name <<endl<< "the nme of lecturer is:" << lecturer <<endl<< "the grade is :" << grade<<endl;
}

char* Course::gat_name()
{
	return name;
}

void Course::set_grade(int grad)
{
	this->grade = grad;
}

void Course::set_lectrer(char* lec)
{
	this->lecturer = lec;
}

Course::~Course()
{
	//delete[]name;
	//delete[]lecturer;
}

