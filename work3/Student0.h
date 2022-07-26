#pragma once
#include <iostream>
#include "Student.h"
#include <typeinfo>
using namespace std;
#include <string.h>
class Student0 : public Student
{
public:
	Student0();
	Student0(char* name , long id , bool is_short);
	Student0(const Student0& S);
	~Student0();
	bool if_exceptional();
	virtual void print()const;
	virtual const char* get_type()const;
	virtual bool get_is_short();

private:
	bool is_short;
};


