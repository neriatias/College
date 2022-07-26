#pragma once
#include <iostream>
using namespace std;
#include "Student.h"
#include <string.h>
class college
{
public:
	college();
	bool add_student();
	bool add_grade(long id, char* name_course, char* name_lectruer, int grade);
	virtual void print_all () const;
	virtual void print_excelent() const;
	void find_types(Student** arr_students , int size_student , int &count0 , int &count1 , int &count2) const;
	virtual int supervisor(char* super);
	void menu();
	~college();

private:
	Student** arr_student;
	int size_student;
};

