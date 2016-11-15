#pragma once

#include <string>
using namespace std;


struct Employee
{
	friend class EmployeeListNode;
	friend class ListOfEmployee;
public:
	Employee();
	Employee(string nameIn, double salaryIn);
		
private:
	string name;
	double salary;
};
