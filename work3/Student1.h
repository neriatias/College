#pragma once
#include <iostream>
#include "Student.h"
#include <string.h>
#include "Course.h"
#include <typeinfo>
using namespace std;

class Student1 : public Student 
{
public:
	Student1();
	Student1(char* name, long id, int size_courses , Course* arr_courses , int year);
	Student1(const Student1& S);
	~Student1();
	virtual bool if_exceptional();
	int get_year();
	virtual void print()const;
	virtual const char* get_type()const;
	virtual Course* get_arr_courses();
	virtual int get_size();
	virtual void set_arr_courses(Course* arr);
	virtual void set_size_courses(int size);
private:
	int size_courses;
	Course* arr_courses;
	int year;
};


