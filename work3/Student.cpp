#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

Student::Student()
{
	name = NULL;
	id = 0;
}

Student::Student(char* N, long I)
{
	name = new char[strlen(N) + 1];
	if (!name)
		exit(1);
	strcpy(name, N);
	id = I;
;
}

Student::Student(const Student& S)
{
	name = new char[strlen(S.name) + 1];
	if (!name)
		exit(1);
	strcpy(name,S.name);
	id = S.id;
}

void Student::print() const
{
	cout << "the name is:" << name <<endl << "the id is:" << id << endl;
}

bool Student::if_exceptional()
{
	return false;
}

long Student::get_id()
{
	return id;
}

const char* Student::get_type() const
{
	return NULL;
}

Student::~Student()
{
	delete[]name;
}

Course* Student::get_arr_courses()
{
	return NULL;
}

int Student::get_size()
{
	return 0;
}

void Student::set_arr_courses(Course* arr)
{
}

void Student::set_size_courses(int size)
{
}

const char* Student::get_supervisor() const
{
	return NULL;
}

const char* Student::gat_name_student()
{
	return name;
}
