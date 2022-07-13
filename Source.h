#pragma once
#include "Student.h"
#include "LinkedList.h"

//add amount of student information that user enter themselves
void addListStudent(LinkedList<Student>& listStudent, int count)
{
	for (int turn = 0; turn < count; turn++)
	{
		string id;
		string name;
		int age;
		cout << "\n*********************************";
		cout << "\nSTUDENT " << turn + 1 << ": ";
		cout << "\nEnter ID number (maximum 8 characters): "; 
		getline(cin, id);
		LinkedList<Student>::Iterator itr = listStudent.find(Student(id));
		if (itr == listStudent.end())
		{
			cout << "\nEnter name: ";
			getline(cin, name);
			cout << "\nEnter age: ";
			cin >> age;
			cin.ignore();
			listStudent.push_back(Student(id, name, age));
		}
		else
		{
			cout << "\nSTUDENT EXIST! INFORMATION IS BELOW: ";
			cout << *itr;
		}
	}
}

//remove student by ID that user enter in
void removeStudentbyID(LinkedList<Student>& listStudent, string ID)
{
	LinkedList<Student>::Iterator itr = listStudent.find(Student(ID));
	if (itr != listStudent.end()) listStudent.remove(itr);
}

//show all information of students in list
void showStudentList(LinkedList<Student>& listStudent, int count)
{
	for (LinkedList<Student>::Iterator iterator = listStudent.begin();
		iterator!= listStudent.end(); iterator++)
	{
		cout << *iterator << endl;
	}
}

//find and return student information by name/ID
void findStudentList(LinkedList<Student>& listStudent, const string& word, bool checkbyID)
{
	int count = 0;
	for (LinkedList<Student>::Iterator iterator = listStudent.begin();
		iterator != listStudent.end(); iterator++)
	{
		if ((!checkbyID) && ((*iterator).getName() == word))
		{
			count++;
			cout << count << ". ";
			cout << *iterator; 
		}
		if ((checkbyID) && ((*iterator).getID() == word))
		{
			count++;
			cout << count << ". \n";
			cout << *iterator;
		}
	}
	if (count == 0) cout << "\nINFORMATION NOT FOUND!";
}

//check whether find student information by name or by ID
void findStudent(LinkedList<Student>& listStudent, const string& s)
{
	bool findbyID;
	if ((s[0] >= '0') && (s[0] <= '9'))
	{
		findbyID = true;
	}
	else
	{
		findbyID = false;
	}
	findStudentList(listStudent, s, findbyID);
}

//sort list of students by ID using bubble sort
void bubbleSort(LinkedList<Student>& listStudent)
{
	for (LinkedList<Student>::Iterator iterator1 = listStudent.begin();
		iterator1 != listStudent.end(); iterator1++)
	{
		for (LinkedList<Student>::Iterator iterator2 = listStudent.begin();
			iterator2 != listStudent.rbegin(); iterator2++)
		{
			if (*iterator2 > *(iterator2+1)) Student::swap(*iterator2, *(iterator2 + 1));
		}
	}
}

//add list of student automatically
void autoAddStudent(LinkedList<Student>& listStudent, int count)
{
	static int studen_id = 1;
	static char name = 'A';
	const string firstname = "Tran Van ";
	const int age = 18;
	for (int turn = 0; turn < count; turn++)
	{
		listStudent.push_back(Student(to_string(studen_id++), firstname + (name++), age));
		listStudent.push_front(Student(to_string(studen_id++), firstname + (name++), age));
	}
}
