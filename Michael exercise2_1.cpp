#include <iostream>
using namespace std;
class employee
{
private:
	int empnum;
	char name[50];
	float sal;
public:
	void inpempy()
	{
		cout<< "\n\n\t Enter the employee number: ";
		cin >> empnum;
		cout << "\n\n\t Enter the employee name: ";
		cin >> name;
		cout << "\n\n\t Enter the employee salary: ";
		cin >> sal;
	}
	void emplydata()
	{
		cout << "\tEmployee data ...";
		cout << "\n\n\t The name of the employee: " << name;
		cout << "\n\n\t The employee number: " << empnum;
		cout << "\n\n\t The salary of the employee: " <<sal;
	}
	
};
int main()
{
	class employee e1;
	e1. inpempy();
	e1.emplydata();
	return 0;
}


