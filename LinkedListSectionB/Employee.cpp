#include "Employee.h"


Employee::Employee()
	: name(""), salary(0.0)
{};

Employee::Employee(string nameIn, double salaryIn)
	:name(nameIn), salary(salaryIn)
{};
