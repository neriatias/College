#pragma once
#include <iostream>
using namespace std;
#include "Course.h"
#include <string.h>
class Student
{
public:
	Student();
	Student(char* N, long I);
	Student(const Student& S);
	~Student();
	virtual void print()const;
	virtual bool if_exceptional();
	long get_id();
	virtual const char* get_type()const;
	virtual Course* get_arr_courses();
	virtual int get_size();
	virtual void set_arr_courses(Course* arr);
	virtual void set_size_courses(int size);
	virtual const char* get_supervisor()const;
	virtual const char* gat_name_student();
protected:
	char* name;
	long id;
};


