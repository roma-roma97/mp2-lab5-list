#include <iostream>
#include <string>
#include "polinom.h"
#include <fstream>

using namespace std;

string PrintPolinom()
{
	string txt;
	cout << "¬ведите полином: ";
	cin >> txt;
	return txt;
}


int main()
{
	string pol1 = "2x2y2z2+5x7y2-4y2z2";
	string pol2 = "-5x7y2+3y3z3+5x-1";
	TPolinom p;
	TPolinom q;
	TPolinom sum;
	p.SetPolinom(pol1);
	q.SetPolinom(pol2);
	sum = q + p;
	cout << sum.Calculate(1, 1, 1) << endl;
	cout<<sum.GetStrPolinom();
	system("pause");
}
