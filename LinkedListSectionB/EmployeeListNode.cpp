#include "EmployeeListNode.h"

EmployeeListNode::EmployeeListNode()
{
	emp.name = "";
	emp.salary = 0.0;
	next = NULL;
}

EmployeeListNode::EmployeeListNode(string nameIn, double salaryIn)
{
	emp.name = nameIn;
	emp.salary = salaryIn;
	next = NULL;
}
