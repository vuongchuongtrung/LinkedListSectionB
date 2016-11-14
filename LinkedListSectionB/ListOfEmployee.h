#pragma once
#include "EmployeeListNode.h"

#include <string>
using namespace std;


class ListOfEmployee
{
	//friend class EmployeeListNode;
public:
	ListOfEmployee();
	~ListOfEmployee();
	bool insert(string nameIn, double salaryIn);
	void displayMessage(string message);
	string horizontalLine();
	void display();
	void display(int sortValue); // any un-zero numbers ==> sort by name || 0 ==> sort by salary
	void deleteMostRecent();
	double getSalary(string nameIn);
	void sortByName();
	void sortBySalary();
	void setColor(int colorValue);

private:
	EmployeeListNode *head;
};
typedef ListOfEmployee *List;
