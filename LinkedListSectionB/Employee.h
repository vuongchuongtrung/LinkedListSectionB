#pragma once

#include <string>
using namespace std;


struct Employee
{
	friend class EmployeeListNode;
	friend class ListOfEmployee;
public:
	Employee();
		
private:
	string name;
	double salary;
};
