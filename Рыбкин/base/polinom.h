#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include<iostream>
#include "list.h"
#include <string>
#include <math.h>

using namespace std;

struct TMonom
{
	double k;
	int power;
	TMonom() :power(0), k(0) {};
};


class TPolinom
{
	TList<TMonom> monoms;
	string polinom;
	void strPolinom();
public:
	TPolinom();
	TPolinom(string _polinom);
	TPolinom(TPolinom &_TPolinom);
	TPolinom& operator=(TPolinom &_TPolinom);
	TPolinom operator+(TPolinom &_TPolinom);
	TPolinom operator-(TPolinom &_TPolinom);
	void SetPolinom(string &_polinom);
	TList<TMonom> GetPolinom();
	string GetStrPolinom();
	double Calculate(const double &x, const double &y, const double &z);
};

#endif 