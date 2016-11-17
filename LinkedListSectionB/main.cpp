#include "ListOfEmployee.h"

int main()
{
	ListOfEmployee list;	
	list.insert("Kadrieh", 40000);
	list.insert("Alfie", 38000);	
	list.insert("Trung", 35000);
	list.insert("Tony", 33000);
	list.insert("Sharon", 32000);
	list.insert("Paul", 35000);

	list.display();

	list.deleteMostRecent(); // Paul
	list.getSalary("Paul");

	//list.sortByName();
	//list.display();

	//list.sortBySalary();
	//list.display();

	// could also passed in: true | false
	list.display(0); // false ==> sort by salary
	list.display(1); // true  ==> sort by name

	list.getSalary("Sharon");

	list.~ListOfEmployee();
	system("pause");
	return 0;
}
