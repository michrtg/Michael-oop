#include <iostream>
using namespace std;
class employee
{
private:
	int empnum;
	float comp;
public:
	void inpempy()
	{
		cout<< "\n\n\t Enter the employee number: ";
		cin >> empnum;
		cout << "\n\n\t Enter the employee compensation : ";
		cin >> comp;
	}
	void emplydata()
	{
		cout << "\tEmployee data ...";
		cout << "\n\n\t The employee number: " << empnum;
		cout << "\n\n\t The salary of the employee: " <<comp;
	}
	
};
int main()
{
	class employee e1;
	e1. inpempy();
	e1.emplydata();
	return 0;
}


