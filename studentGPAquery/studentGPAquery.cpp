// studentGPAquery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct student
{
	string first_name;
	string last_name;
	double GPA;

	student(){}
	~student(){}
	struct student *next;
};

student *head = NULL;

void mainMenu()
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
}

void addRecord()
{
	cout<<endl;
	cout<<"Add record:"<<endl;
	cout<<endl;

	struct student *temp, *alt;
	temp = new student;

	cout<<"What is the student's last name: ";
	cin>>temp->last_name;
	cout<<"What is the student's first name: ";
	cin>>temp->first_name;
	cout<<"What is student's GPA: ";
	cin>>temp->GPA;
	temp->next = NULL;

	if(head == NULL)
		head = temp;
	else
	{
		alt = head;
		while(alt->next != NULL)
		{
			alt = alt->next;
		}
		alt->next = temp;
	}
}

void deleteRecord()
{

	string lname;

	student *temp, *alt;
	temp = head;

	cout<<endl;
	cout<<"Last name of student to delete: ";
	cin>>lname;

	while(temp->last_name != lname)
	{

		alt = temp;
		temp = temp->next;
	}
	if(temp-> != NULL)
	{
		if(temp == 


	delete temp;
	cout<<"Deleted"<<endl;


void viewRecords()
{
    student *temp;
    temp = head;
 
     do
     {
        if(temp == NULL)
			cout<<"Empty List."<<endl;
         else
         {
            cout<<"Name: "<<temp->last_name<<", ";
            cout<<temp->first_name<<endl;
            cout<<"GPA: "<<temp->GPA<<endl;
            cout<<endl;
            temp = temp->next;
          }
     }
	 while(temp != NULL);
}
/*
void sortRecord()
{
	student *itr;

	for(itr == student)
	{
		return left.last_name < right.last_name;
		sort (student.begin(), student.end());

	}
}
*/
int _tmain(int argc, _TCHAR* argv[])
{
	char choice;
	
	do{
		mainMenu();
			cout<<"Command?: ";
			if(cin>>choice)
				switch(choice)
				{
				case 'A':
					addRecord();
					break;
				case 'D':
					deleteRecord();
					break;
				case 'V':
					viewRecords();
					break;
				//case 'T':
					//traverseRecord();
					//break;
				}
	}
	while(choice != 'Q');
		cout<<endl;
		cout<<"Terminating.."<<endl;

	system("PAUSE");
	return 0;
}

