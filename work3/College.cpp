#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "College.h"
#include "Student0.h"
#include "Student1.h"
#include "Student2.h"
#include "Course.h"
#include <typeinfo>
# define N 20

college::college()
{
	arr_student = NULL;
	size_student = 0;
}

bool college::add_student()
{
	Course* arr_courses =NULL;
	Student** temp_arr = NULL;
	int size_Student1 = 0;
	int temp_year;
	bool temp_mechina;
	char temp[N];
	int type;
	char* temp_name, * temp_thesis, * temp_supervisor;
	long temp_id;
	cout << "please enter id "<<endl;
	cin >> temp_id;
	if (size_student < 1)
	arr_student = new Student * [size_student];
		for (int i = 0; i < size_student; i++)
		{
			if (arr_student[i]->get_id() == temp_id)
				return false;
		}
	cout << "please enter the name of student" << endl;
	cin >> temp;
	temp_name = new char[strlen(temp) + 1];
	if (!temp_name)
		exit(1);
	strcpy(temp_name, temp);
	cout << "please enter the type of student (0,1,2)" << endl;
	cin >> type;
	switch (type)
	{
	case 0:
		cout << "plesae enter 1 if you are in short preparatory and 0 if you are in long preparatory" << endl;
		cin >> temp_mechina;
		temp_arr = new Student * [size_student + 1];
		if (!temp_arr)
			return false;
		for (int i = 0; i < size_student+1; i++)
		{
			temp_arr[i] = arr_student[i];
		}
		temp_arr[size_student] =  new Student0(temp_name, temp_id, temp_mechina);
		delete[]arr_student;
		 arr_student = new Student * [size_student + 1];
		arr_student = temp_arr;
		size_student++;
		return true;
		break;
	case 1:
		cout << "please enter your year in the study" << endl;
		cin >> temp_year;
		 temp_arr = new Student * [size_student + 1];
		if (!temp_arr)
			return false;
		for (int i = 0; i < size_student; i++)
		{
			temp_arr[i] = arr_student[i];
		}
		temp_arr[size_student] = new Student1(temp_name, temp_id,size_Student1 ,arr_courses,temp_year);
		delete[]arr_student;
		arr_student = new Student * [size_student + 1];
		arr_student = temp_arr;
		size_student++;
		return true;
		break;
	case 2:
		cout << "please enter the subject of thesis" << endl;
		cin >> temp;
			temp_thesis = new char[strlen(temp) + 1];
		if (!temp_thesis)
			exit(1);
		strcpy(temp_thesis, temp);
		cout << "please enter the name of supervisor" << endl;
		cin >> temp; 
		temp_supervisor = new char[strlen(temp) + 1];
		if (!temp_supervisor)
			exit(1);
		strcpy(temp_supervisor, temp);
		temp_arr = new Student * [size_student + 1];
		if (!temp_arr)
			return false;
		for (int i = 0; i < size_student; i++)
		{
			temp_arr[i] = arr_student[i];
		}
		temp_arr[size_student] = new Student2(temp_name, temp_id, temp_thesis, temp_supervisor);
		delete[]arr_student;
		arr_student = new Student * [size_student + 1];
		arr_student = temp_arr;
		size_student++;
		return true;
		break;
	default:
		cout << "the input is not leg" << endl;
		return false;
		break;
	}
	


}

bool college::add_grade(long id, char* name_course, char* name_lectruer, int grade)
{
	Course* temp;
	for (int i = 0; i < size_student; i++)
	{
		if (arr_student[i]->get_id() == id && strcmp(arr_student[i]->get_type(), "Student1") == 0)
		{
			for (int j = 0; j < arr_student[i]->get_size(); j++)
			{
				
					if (strcmp(name_course, arr_student[i]->get_arr_courses()[j].gat_name())== 0)
					{
							arr_student[i]->get_arr_courses()[j].set_grade(grade);
							arr_student[i]->get_arr_courses()[j].set_lectrer(name_lectruer);
							return true;
					}
			}
			temp = new Course[arr_student[i]->get_size() + 1];
			if (!temp)
				return false;
			for (int k = 0; k < arr_student[i]->get_size(); k++)
			{
				temp[k] = arr_student[i]->get_arr_courses()[k];
			}
			temp[arr_student[i]->get_size()] = Course(name_course, name_lectruer, grade);
			arr_student[i]->set_arr_courses(new Course[arr_student[i]->get_size() + 1]);
			if(!arr_student[i]->get_arr_courses())
				return false;
			arr_student[i]->set_arr_courses(temp);
			arr_student[i]->set_size_courses(arr_student[i]->get_size() + 1);
			
			return true;
		}
	}
		return false;
}

void college::print_all() const
{
	for (int i = 0; i < size_student; i++)
	{
			 arr_student[i]->print();
	}
}

void college::print_excelent() const
{
	cout << "the exceptional students is :" << endl;
	for (int i = 0; i < size_student; i++)
	{
		if (arr_student[i]->if_exceptional())
			arr_student[i]->Student::print();
	}
}

void college::find_types(Student** arr_students, int size_student, int& count0, int& count1, int& count2) const
{
	count0 = 0;
	count1 = 0;
	count2 = 0;
	for (int i = 0; i < size_student; i++)
	{
		if (strcmp("Student0", arr_student[i]->get_type()) == 0)
			count0++;
		if (strcmp("Student1", arr_student[i]->get_type()) == 0)
			count1++;
		if (strcmp("Student2", arr_student[i]->get_type()) == 0)
			count2++;
	}
}

int college::supervisor(char* super)
{
	int counter = 0 ;
	for (int i = 0; i < size_student; i++)
	{
		if (strcmp(arr_student[i]->get_type(), "Student2") == 0) 
		{
			if (strcmp(arr_student[i]->get_supervisor(), super) == 0)
			{
				if (counter == 0)
					cout << "this student are learn with this lectruer:  " << endl;
				cout << arr_student[i]->gat_name_student() << endl;
				counter++;;
			}
		}
		
	}
	if (counter == 0)
		cout << "this supervisor not real" << endl;
	return counter;
}

void college::menu()
{
	int i, j, k;
	int counter = 0;
	long menu_id;
	int menu_grade;
	char* menu_course, * menu_lecturer, * menu_lecturer2;
	char temp[N];
	int choose =2;
	while (choose>0&&choose<8)
	{
		cout << "1-Add student" << endl << "2-Add grade" << endl << "3-Print all" <<endl<< "4-Print excellent" << endl << "5-Types of student" << endl << "6-Supervisor" << endl << "7-Quit" << endl;
		cout << "please enter your choose" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			if (add_student())
				cout << "the action was successful" << endl;
			else
				cout << "this student is exists"<<endl;
			continue;
		case 2:
			cout << "please enter the id" << endl;
			cin >> menu_id;
			cout << "please enter the grade" << endl;
			cin >> menu_grade;
			cout << "please enter the name of course" << endl;
			cin >> temp;
			menu_course = new char[strlen(temp) + 1];
			if (!menu_course)
				exit(1);
			strcpy(menu_course, temp);
			cout << "please enter the name of lectruer" << endl;
			cin >> temp;
			menu_lecturer = new char[strlen(temp) + 1];
			if (!menu_lecturer)
				exit(1);
			strcpy(menu_lecturer, temp);
			if (add_grade(menu_id, menu_course, menu_lecturer, menu_grade))
				cout << "the action was successful"<<endl;
			else
			cout<< "the action was not successful" << endl;
			continue;
		case 3:
			print_all();
			continue;
		case 4:
			print_excelent();
			continue;
		case 5:
			find_types(arr_student, size_student, i, j, k);
			cout << "there are " << i << " student in mechina  and " << j << " students in BA and  " << k << " students in MA" << endl;
			continue;
		case 6:
			cout << "please enter name of lecturer the you want to check" << endl;
			cin >> temp;
			menu_lecturer2 = new char[strlen(temp) + 1];
			if (!menu_lecturer2)
				exit(1);
			strcpy(menu_lecturer2, temp);
			counter = supervisor(menu_lecturer2);
			cout << "there are " << counter << "  that learn in this supervisor"<<endl;
			continue;
		case 7:
			cout << "the end" << endl;
			choose = 9;
			break;
		default:
			cout << "please enter number between 1 to 7" << endl;
			choose = 3;
			continue;
		}
	}
}

college::~college()
{
	delete[]arr_student;
}


