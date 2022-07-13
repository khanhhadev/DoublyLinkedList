#include "Source.h"

int main()
{
	LinkedList<Student> myList;

	//add list of student automatically
	autoAddStudent(myList, 5);
	while (true)
	{
		int number;
		cout << "**************************************************";
		cout << "\n\nEnter number of function that you want to choose:"
			<< endl << "1. Add students list"
			<< endl << "2. Find student information"
			<< endl << "3. Show all students information"
			<< endl << "4. Remove student information by ID"
			<< endl << "5. Sort list of students by ID"
			<< endl << "0. End program"
			<< endl << "Function: ";
		cin >> number;
		cin.ignore();
		switch (number)
		{
		case 1:
		{
			int count;
			cout << "\nEnter number of students that you want to add:";
			cin >> count; cin.ignore();
			addListStudent(myList, count);
		}
		break;
		case 2:
		{
			string word;
			cout << "\nEnter information (ID/Name) of student that you want to find:";
			getline(cin, word);
			findStudent(myList, word);
		}
		break;
		case 3:
		{
			showStudentList(myList, myList.size());
		}
		break;
		case 4:
		{
			string ID;
			cout << "\nEnter information ID of student that you want to remove:";
			getline(cin, ID);
			removeStudentbyID(myList, ID);
			cout << "\nStudent information was removed!";
		}
		break; 
		case 5:
		{
			string ID;
			cout << "\nList of students after sorting:";
			bubbleSort(myList);
			autoPeekStudent(myList, myList.size());
		}
		break;
		case 0:
		{
			return 0;
		}
		break;
		default:
		{
			cout << "Invalid input";
		}
		break;
		}
		cout << "\n";
	}
	return 0;
	addListStudent(myList, 2);
	return 0;
}