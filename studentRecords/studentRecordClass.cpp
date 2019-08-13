
#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class student
{
public:
		string first_name;
		string last_name;
		double GPA;

		student *next;
};

class studentList
{
	friend ostream &operator<<(ostream &, const studentList&);//output stream for viewRecords()

public:
	studentList();//constructor
	~studentList(){}//destructor
	void addRecord(string lname, string fname, double gpa);
	void viewRecords();
	student getStudent(string lname, string fname);
	void deleteRecord(string lname, string fname);

private:
	student *initial;
	student *current;
};

studentList::studentList()//Implementataion of studentList
{
	initial = 0;
	current = 0;
}

void studentList::addRecord(string lname, string fname, double gpa)
{
	student *temp, *alt, *secn;
	temp = new student;
	
	(temp->last_name) = lname;
	(temp->first_name) = fname;
	(temp->GPA) = gpa;
	(temp->next) = NULL;

	if(initial == 0 || initial->last_name >= temp->last_name) //entry of last name first
	{
		temp->next = initial;
		initial = temp;
		current = initial;
	}
	else
	{
		alt = initial;
		while(alt != 0 && (alt->last_name < temp->last_name)) //integrated sorting of last names
		{
			secn = alt;
			alt = alt->next;
		}
			if (secn != 0)
				secn->next = temp;
		
			if (alt != 0)
				temp->next = alt;
	}
}

void studentList::deleteRecord(string lname, string fname)
{
	student *temp, *alt;

	cout<<"Enter in the last name to delete: ";
	cin>>lname;
	cout<<endl;

	temp = initial;
	while (temp->last_name != lname)
	{
		alt = temp;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		if (temp == initial)
		{
			initial = initial->next;
			delete (temp);
		}
		else
		{
			alt->next = temp->next;
			delete (temp);
		}
	}
}

ostream &operator<<(ostream &output, const studentList &o)
{
	student *temp;
	temp = o.initial;

	if(temp == 0)
		cout<<"List Empty."<<endl;

	while (temp != 0)
	{
		cout<<"Name: "<<temp->last_name<<", ";
        cout<<temp->first_name<<endl;
        cout<<"GPA: "<<temp->GPA<<endl;
        temp = temp->next;
		cout<<endl;
	}
	return output;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char choice;
	studentList student;

	do
	{
			cout<<endl;
	cout<<"++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"            MAIN MENU             "<<endl;
	cout<<"    Choose from the following:    "<<endl;
	cout<<"[A]dd a record                    "<<endl;
	cout<<"[D]elete a record                 "<<endl;
	cout<<"[V]iew all records                "<<endl;
	cout<<"[Q]uit program                    "<<endl;
	cout<<"++++++++++++++++++++++++++++++++++"<<endl;
	cout<<endl;
	cout<<"Command ?: ";
	cin>>choice;
	cout<<endl;

		string lname;
		string fname;
		double gpa;

		switch(choice)
		{
		case 'A':
			cout<<"What is the student's last name: ";
			cin>>lname;
			cout<<"What is the student's first name: ";
			cin>>fname;
			cout<<"What is student's GPA: ";
			cin>>gpa;
			cout<<endl;
			student.addRecord(lname, fname, gpa);
			break;
		case 'D':
			student.deleteRecord(lname, fname);
			break;
		case 'V':
			cout<<student;
			break;
		}
	}
	while(choice != 'Q');
	cout<<endl;
	cout<<"Terminating..."<<endl;
	cout<<endl;

	system("PAUSE");
	return 0;
}

