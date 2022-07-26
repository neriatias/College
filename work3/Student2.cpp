#define _CRT_SECURE_NO_WARNINGS
#include "Student2.h"

Student2::Student2() :Student()
{
	thesis = NULL;
	supervisor = NULL;
}

Student2::Student2(char* name, long id, char* thesis, char* supervisor) :Student(name, id)
{
	this->thesis = new char[strlen(thesis) +1];
	if (!this->thesis)
		exit(1);
	strcpy(this->thesis, thesis);
	this->supervisor = new char[strlen(supervisor) +1];
	if (!this->supervisor)
		exit(1);
	strcpy(this->supervisor, supervisor);
}

Student2::Student2(const Student2& S) :Student(S)
{
	this->thesis = new char[strlen(S.thesis) + 1];
	if (!this->thesis)
		exit(1);
	strcpy(this->thesis, S.thesis);
	this->supervisor = new char[strlen(S.supervisor) + 1];
	if (!this->supervisor)
		exit(1);
	strcpy(this->supervisor, S.supervisor);
}

Student2::~Student2()
{
}

bool Student2::if_exceptional()
{
	return true;
}

void Student2::print() const
{
	Student::print();
	cout << "the name of the thesis is:" << thesis << "  the supervisor is:" << supervisor<<endl;
}

const char* Student2::get_type() const
{
	return "Student2";
}

const char* Student2::get_supervisor() const
{
	return supervisor;
}

