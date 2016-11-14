#include "EmployeeListNode.h"


EmployeeListNode::EmployeeListNode(string nameIn, double salaryIn)
{
	emp.name = nameIn;
	emp.salary = salaryIn;
	next = NULL;
}
