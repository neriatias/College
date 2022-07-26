#pragma once
#include <iostream>
using namespace std;
#include <string.h>
class Course
{
public:
	Course();
	Course(char* N, char* L, int G);
	Course(const Course &C);
	virtual ~Course();
	int get_grade();
	virtual void print() const;
    virtual char* gat_name();
    virtual void set_grade(int grad);
    virtual void set_lectrer(char* lec);
protected:
	char* name;
	char* lecturer;
	int grade;


};

