#pragma once
#include "Employee.h"
#include "ListOfEmployee.h"


class EmployeeListNode
{
	friend class ListOfEmployee;
public:
	EmployeeListNode();
	EmployeeListNode(string nameIn, double salaryIn);		

private:
	Employee emp;
	EmployeeListNode *next;
};
typedef EmployeeListNode *NodePtr;
