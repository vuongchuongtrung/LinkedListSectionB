#pragma once
#include "Employee.h"
#include "ListOfEmployee.h"

class EmployeeListNode
{
	friend class ListOfEmployee;
public:
	EmployeeListNode(string nameIn, double salaryIn);

private:
	Employee emp;
	EmployeeListNode *next;
};
typedef EmployeeListNode *NodePtr;


EmployeeListNode::EmployeeListNode(string nameIn, double salaryIn)
{
	emp.name = nameIn;
	emp.salary = salaryIn;
	next = NULL;
}
