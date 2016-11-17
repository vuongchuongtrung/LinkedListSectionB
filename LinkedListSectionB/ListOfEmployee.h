#pragma once
#include "EmployeeListNode.h"

#include <ostream>
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

	// any un-zero numbers ==> sort by name || 0 ==> sort by salary
	// I just simply want to practice this, rather than pass in the real boolean type
	void display(int sortValue); 
	
	void deleteMostRecent();
	double getSalary(string nameIn);
	void sortByName();
	void sortBySalary();
	void setColor(int colorValue);
	void displayWarningMessage(ostream &str, string message);

private:
	EmployeeListNode *head;
};
typedef ListOfEmployee *List;
