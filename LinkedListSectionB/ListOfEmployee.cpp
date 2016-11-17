#include "ListOfEmployee.h"
#include "Employee.h"
#include "EmployeeListNode.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <Windows.h>
using namespace std;


ListOfEmployee::ListOfEmployee()
	:head(NULL)
{}

ListOfEmployee::~ListOfEmployee()
{
	NodePtr tempPtr;
	while (head)
	{
		tempPtr = head;
		head = head->next;
		delete tempPtr;
	}
}

bool ListOfEmployee::insert(string nameIn, double salaryIn)
{
	EmployeeListNode *newNode = new EmployeeListNode(nameIn, salaryIn);

	if (!newNode)
	{
		return false; // failure
	}
	newNode->next = head;
	head = newNode;
	return true; // success
}

void ListOfEmployee::displayMessage(string message)
{
	setColor(11); // light green
	cout << message << endl;
	setColor(7); // reset to white
}

string ListOfEmployee::horizontalLine()
{
	//return "==============================";
	return "------------------------------";
}

/*
 * Usage: used/modified
 * Availability: http://stackoverflow.com/questions/17530408/print-integer-with-thousands-and-millions-separator
 * On 07/11/2016, at 07:45
 *
 * imbue() the output stream with a locale that has the desired separator. For example:
 * 	 #include <iostream>
 * 	 #include <locale>
 * 	 int main()
 * 	 {
 * 		 // imbue the output stream with a locale.
 * 		 int i = 45749785;
 * 		 std::cout << i << "\n";
 *
 * 		 std::cout.imbue(std::locale(""));
 * 		 std::cout << i << "\n";
 * 	 }
 */
void ListOfEmployee::display()
{
	// imbue the output stream with a locale.
	// thousand separator for number ==> e.g.: 35,000
	cout.imbue(locale(""));

	NodePtr tempPtr = head;

	if (!tempPtr) // if empty list
	{
		cout << "Cannot display empty list!" << endl;
	}
	else
	{
		cout << horizontalLine() << "\n"
			<< setw(2) << ""
			<< left << setw(18) << "Employee's Name"
			<< right << setw(9) << "Salary" << "\n"
			<< horizontalLine() << endl;
		while (tempPtr != NULL)
		{
			cout << setw(2) << ""
				<< left << setw(18) << tempPtr->emp.name
				<< right << setw(9) << setprecision(0) << fixed << tempPtr->emp.salary << endl;
			tempPtr = tempPtr->next;
		}
		cout << horizontalLine() << "\n" << endl;
	}
}

void ListOfEmployee::display(int sortValue)
{
	// imbue the output stream with a locale.
	// thousand separator for number ==> e.g.: 35,000
	cout.imbue(locale(""));

	NodePtr tempPtr = head;

	if (!tempPtr) // if empty list
	{
		cout << "Cannot display empty list!" << endl;
	}
	else
	{
		if (sortValue) // true ==> sort by name ==> any un-zero number
		{
			displayMessage("Sort By Name");
			sortByName();
			display();
		}
		else // sort by salary
		{
			displayMessage("Sort By Salary");
			sortBySalary();
			display();
		}
	}
}

void ListOfEmployee::deleteMostRecent()
{
	if (!head) // if head is not empty
	{
		setColor(12); // light red
		cout << "Delete cannot be done with an empty list!\n" << endl;
		setColor(7); // reset to white
	}
	else // insert at front, so need to delete at front for most recent
	{
		NodePtr tempPtr = head;
		head = head->next;
		string name = tempPtr->emp.name;
		double salary = tempPtr->emp.salary;
		delete tempPtr;

		// I want to make sure it is deleted before display the message
		// Therefore, I need to store employee's details into variables
		setColor(14);
		cout << "Deleting most recent....." << endl;
		setColor(12);
		cout << name << " : " << salary << " is deleted!\n" << endl;
		setColor(7);
	}
}

double ListOfEmployee::getSalary(string nameIn)
{
	// imbue the output stream with a locale.
	// thousand separator for number ==> e.g.: 35,000
	cout.imbue(locale(""));

	bool isFound = false;
	double salary = 0;
	EmployeeListNode *currentNode = head;

	if (!head)
	{
		setColor(12);
		cout << "The list is empty!\n" << endl;
		setColor(7);
	}
	else
	{
		while (currentNode != NULL)
		{
			if (currentNode->emp.name == nameIn)
			{
				salary = currentNode->emp.salary;
				cout << nameIn << " salary is: " << setprecision(0) << fixed << salary << "\n" << endl;
				isFound = true;
			}
			currentNode = currentNode->next;
		}
		if (!isFound) // if not found
		{
			setColor(12);
			cout << nameIn << " could NOT be found in the list!\n" << endl;
			setColor(7);
			// the code below worked
			//displayWarningMessage(cout, nameIn + " could NOT be found in the list!\n");
		}
	}
	return salary;
}

/*
 * usage: used/modifed
 * availability: http://www.cplusplus.com/forum/general/143896/
 * on 08/11/2016, at 20:30
 */
void ListOfEmployee::sortByName()
{
	EmployeeListNode *tempPtr1 = head;
	while (tempPtr1 != NULL)
	{
		EmployeeListNode *tempPtr2 = tempPtr1;
		while (tempPtr2 != NULL)
		{
			if (tempPtr1->emp.name > tempPtr2->emp.name)
			{
				string name;
				double salary;
				name = tempPtr1->emp.name;
				salary = tempPtr1->emp.salary;

				tempPtr1->emp.name = tempPtr2->emp.name;
				tempPtr1->emp.salary = tempPtr2->emp.salary;

				tempPtr2->emp.name = name;
				tempPtr2->emp.salary = salary;
			}
			tempPtr2 = tempPtr2->next;
		}
		tempPtr1 = tempPtr1->next;
	}
}

/*
 * usage: used/modifed
 * availability: http://stackoverflow.com/questions/12927790/sort-a-linked-list-in-c
 * on 08/11/2016, at 20:30
 */
void ListOfEmployee::sortBySalary()
{
	for (EmployeeListNode *tempPtr1 = head; tempPtr1 != NULL; tempPtr1 = tempPtr1->next)
	{
		for (EmployeeListNode *tempPtr2 = tempPtr1; tempPtr2 != NULL; tempPtr2 = tempPtr2->next)
		{
			if (tempPtr1->emp.salary > tempPtr2->emp.salary)
			{
				EmployeeListNode temp = *tempPtr1;

				tempPtr1->emp.name = tempPtr2->emp.name;
				tempPtr1->emp.salary = tempPtr2->emp.salary;

				tempPtr2->emp.name = temp.emp.name;
				tempPtr2->emp.salary = temp.emp.salary;
			}
		}
	}
}

/*
 * usage: used/modified
 * availability: http://www.cplusplus.com/forum/beginner/77879/
 * on 03/11/2016, at 13:30
 *
 * Color values:
 * 0 = Black		8 = Gray
 * 1 = Blue			9 = Light Blue
 * 2 = Green		A = Light Green
 * 3 = Aqua			B = Light Aqua
 * 4 = Red			C = Light Red
 * 5 = Purple		D = Light Purple
 * 6 = Yellow		E = Light Yellow
 * 7 = White		F = Bright White
 */
void ListOfEmployee::setColor(int colorValue)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorValue);
}

void ListOfEmployee::displayWarningMessage(ostream &str, string message)
{
	setColor(12);
	str << message << endl;
	setColor(7);
}
