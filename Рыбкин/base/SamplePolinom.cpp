#include <iostream>
#include <string>
#include "polinom.h"
#include <fstream>

using namespace std;

int main()
{
	string pol1;
	string pol2;
	TPolinom p;
	TPolinom q;
	TPolinom add, sub;
	double x = 1, y = 1, z = 1;
	cout << "Input 1 polinom: ";
	cin >> pol1;
	cout << endl;
	cout << "Input 2 polinom: ";
	cin >> pol2;
	cout << endl;
	cout << "Input x y z: ";
	cin >> x >> y >> z;
	cout << endl;
	p.SetPolinom(pol1);
	q.SetPolinom(pol2);
	add = p + q;
	sub = p - q;
	cout << "add: " << add.GetStrPolinom() << endl;
	cout << "sub 1-2:" << sub.GetStrPolinom() << endl;
	cout << "Calculate 1 polinom: " << p.Calculate(x, y, z) << endl;
	cout << "Calculate 2 polinom: " << q.Calculate(x, y, z) << endl;
	cout << "calculate add: " << add.Calculate(x, y, z) << endl;
	cout << "calculate sub: " << sub.Calculate(x, y, z);
	system("pause");
}
