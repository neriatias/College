#include "Student0.h"


Student0::Student0():Student()
{
	is_short = 0;
}

Student0::Student0(char* name, long id, bool is_short):Student(name,id)
{
	this->is_short = is_short;
}

Student0::Student0(const Student0& S):Student(S)
{
	is_short = S.is_short;
}

Student0::~Student0()
{
}

bool Student0::if_exceptional()
{
	return false;
}

void Student0::print() const
{
	Student::print();
	if (is_short)
		cout << "the student learn in short preparatory" << endl;
	else
		cout << "the student learn in long preparatory" << endl;
}

const char* Student0::get_type() const
{
	return "Student0";
}

bool Student0::get_is_short()
{
	return is_short;
}
