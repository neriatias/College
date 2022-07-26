#define _CRT_SECURE_NO_WARNINGS
#include "Student1.h"

Student1::Student1() :Student ()
{
	year = 0;
	size_courses = 0;
	arr_courses = NULL;
}

Student1::Student1(char* name, long id, int size_courses, Course* arr_courses, int year) :Student(name, id)
{
	this->year = year;
	this->size_courses = size_courses;
	this->arr_courses = new Course[size_courses];
	for (int i = 0; i < size_courses; i++)
	{
		this->arr_courses[i] = arr_courses[i];
	}
}

Student1::Student1(const Student1& S) :Student(S)
{
	year = S.year;
	size_courses = S.size_courses;
	for (int i = 0; i < size_courses; i++)
	{
		this->arr_courses[i] = S.arr_courses[i];
	}
}

Student1::~Student1()
{
	delete[]arr_courses;
}

bool Student1::if_exceptional()
{
	float avarage = 0.0;
	for (int i = 0; i < size_courses; i++)
		avarage += arr_courses[i].get_grade();
	avarage /= size_courses;
	if ((year == 1 || year == 2) && avarage >= 90)
		return true;
	if ((year == 3 || year == 4) && avarage >= 85)
		return true;
	return false;
	
}

int Student1::get_year()
{
	return year;
}

void Student1::print() const
{
	float avarage = 0;
	Student::print();
	cout << "the student learn " <<size_courses << " courses" << endl;
	for (int i = 0; i < size_courses; i++)
	{
		arr_courses[i].print();
		avarage += arr_courses[i].get_grade();
	}
	cout << "this is the year of student:" << year<<endl;
	if (avarage!=0)
	{
		avarage /= size_courses;
	}
	cout << "the avarage is: " << avarage << endl;
}

const char* Student1::get_type() const
{
	return "Student1";
}

Course* Student1::get_arr_courses()
{
	return arr_courses;
}

int Student1::get_size()
{
	return size_courses;
}

void Student1::set_arr_courses(Course* arr)
{
	this->arr_courses = arr;
}

void Student1::set_size_courses(int size)
{
	this->size_courses = size;
}

