#pragma once
#include <iostream>
#include "Student.h"
#include <string.h>
#include <typeinfo>
using namespace std;
class Student2 :public Student
{
public:
	Student2();
	Student2(char* name, long id, char* thesis, char* supervisor);
	Student2(const Student2& S);
	~Student2();
	bool if_exceptional();
	virtual void print()const;
	virtual const char* get_type()const;
	virtual const char* get_supervisor()const;
private:
	char* thesis;
	char* supervisor;
};
