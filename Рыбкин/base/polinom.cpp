#include "polinom.h"
#include "cstdlib"

using namespace std;

TPolinom::TPolinom()
{
	polinom = "";
}

TPolinom::TPolinom(string _polinom)
{
	SetPolinom(_polinom);
}

TPolinom::TPolinom(TPolinom &_TPolinom)
{
	polinom = _TPolinom.polinom;
	monoms = _TPolinom.monoms;
}

TPolinom& TPolinom::operator=(TPolinom &_TPolinom)
{
	if (this == &_TPolinom)
		return *this;
	monoms = _TPolinom.monoms;
	polinom = _TPolinom.polinom;
	return *this;
}

TPolinom TPolinom::operator+(TPolinom &_Polinom)
{
	TPolinom tmp;
	TMonom monom;
	int i = 0, j = 0;
	while ((i < monoms.GetSize()) && (j < _Polinom.monoms.GetSize()))
	{
		if (monoms[i].power == _Polinom.monoms[j].power)
		{
			if ((monoms[i].k + _Polinom.monoms[j].k) != 0)
			{
				monom.k = monoms[i].k + _Polinom.monoms[j].k;
				monom.power = monoms[i].power;
				tmp.monoms.Push_back(monom);
				j++;
				i++;
				continue;
			}
			j++;
			i++;
		}
		if (monoms[i].power > _Polinom.monoms[j].power)
		{
			tmp.monoms.Push_back(monoms[i]);
			i++;
		}
		else
		{
			tmp.monoms.Push_back(_Polinom.monoms[j]);
			j++;
		}
	}
	if (i == monoms.GetSize())
		while (j < _Polinom.monoms.GetSize())
		{
			tmp.monoms.Push_back(_Polinom.monoms[j]);
			j++;
		}
	else
		while (i < _Polinom.monoms.GetSize())
		{
			tmp.monoms.Push_back(monoms[i]);
			i++;
		}
	tmp.strPolinom();
	return tmp;
}

TPolinom TPolinom::operator-(TPolinom &_Polinom)
{
	TPolinom tmp;
	TMonom monom;
	int i = 0, j = 0;
	while ((i < monoms.GetSize()) && (j < _Polinom.monoms.GetSize()))
	{
		if (monoms[i].power == _Polinom.monoms[j].power)
		{
			if ((monoms[i].k + _Polinom.monoms[j].k) != 0)
			{
				monom.k = monoms[i].k - _Polinom.monoms[j].k;
				monom.power = monoms[i].power;
				tmp.monoms.Push_back(monom);
				j++;
				i++;
				continue;
			}
			j++;
			i++;
		}
		if (monoms[i].power > _Polinom.monoms[j].power)
		{
			monom = monoms[i];
			monom.k *= -1;
			tmp.monoms.Push_back(monom);
			i++;
			continue;
		}
		else
		{
			monom = _Polinom.monoms[i];
			monom.k *= -1;
			tmp.monoms.Push_back(monom);
			j++;
			continue;
		}
	}
	if (i == monoms.GetSize())
		while (j < _Polinom.monoms.GetSize())
		{
			monom = _Polinom.monoms[i];
			monom.k *= -1;
			tmp.monoms.Push_back(monom);
			j++;
		}
	else
		while (j < _Polinom.monoms.GetSize())
		{
			monom = monoms[i];
			monom.k *= -1;
			tmp.monoms.Push_back(monom);
			i++;
		}
	tmp.strPolinom();
	return tmp;
}

double TPolinom::Calculate(const double &x, const double &y, const double &z)
{
	double res = 0;
	double monom = 1;
	for (int i = 0; i < monoms.GetSize(); i++)
	{
		if (monoms[i].power % 10 != 0)
			monom *= pow(z, monoms[i].power % 10);
		if ((monoms[i].power / 10) % 10 != 0)
			monom *= pow(y, (monoms[i].power / 10) % 10);
		if (monoms[i].power / 100 != 0)
			monom *= pow(x, monoms[i].power / 100);
		res += monom * monoms[i].k;;
		monom = 1;
	}
	return res;
}

void TPolinom::SetPolinom(string &_polinom)
{
	TMonom monom;
	int flag = 0;
	int sign = 1;
	int i = 0;
	string str;
	polinom = _polinom;
	while (i < _polinom.length())
	{
		while ((i != _polinom.length()) && _polinom[i] != '-' && _polinom[i] != '+')
		{
			while ((_polinom[i] >= '0'&&_polinom[i] <= '9') || _polinom[i] == '.')
				str += _polinom[i++];
			switch (flag) {
			case 0: monom.k = atof(str.c_str())*sign; str = ""; flag = -1; break;
			case 1: monom.power = atoi(str.c_str()) * 100; str = ""; flag = -1; break;
			case 2: monom.power += atoi(str.c_str()) * 10; str = ""; flag = -1; break;
			case 3: monom.power += atoi(str.c_str());  str = ""; flag = -1; break;
			}
			if (_polinom[i] == 'x')
			{
				i++;
				flag = 1;
				continue;
			}
			if (_polinom[i] == 'y')
			{
				i++;
				flag = 2;
				continue;
			}
			if (_polinom[i] == 'z')
			{
				i++;
				flag = 3;
				continue;
			}
		}
		if (_polinom[i] != '-')
			sign = 1;
		else
			sign = -1;
		i++;
		if (monoms.GetSize() == 0)
			monoms.Push_back(monom);
		else if (monom.power > monoms[0].power)
			monoms.Push_begin(monom);
		else if (monom.power < monoms[monoms.GetSize() - 1].power)
			monoms.Push_back(monom);
		else
			for (int z = 0; z < monoms.GetSize(); z++)
				if (monoms[z].power < monom.power)
				{
					monoms.Insert(z - 1, monom);
					break;
				}
		flag = 0;
		monom.power = 0;
	}
}

TList<TMonom> TPolinom::GetPolinom()
{
	return monoms;
}

string TPolinom::GetStrPolinom()
{
	return polinom;
}

void TPolinom::strPolinom()
{
	polinom = "";
	polinom += to_string(monoms[0].k);
	if (monoms[0].power / 100 != 0)
		polinom = polinom + "x" + to_string(monoms[0].power / 100);
	if ((monoms[0].power / 10) % 10 != 0)
		polinom = polinom + "y" + to_string((monoms[0].power / 10) % 10);
	if (monoms[0].power % 10 != 0)
		polinom = polinom + "z" + to_string(monoms[0].power % 10);
	for (int i = 1; i < monoms.GetSize(); i++)
	{
		if (monoms[i].k > 0)
			polinom += "+";
		polinom += to_string(monoms[i].k);
		if (monoms[i].power / 100 != 0)
			polinom = polinom + "x" + to_string(monoms[i].power / 100);
		if ((monoms[i].power / 10) % 10 != 0)
			polinom = polinom + "y" + to_string((monoms[i].power / 10) % 10);
		if (monoms[i].power % 10 != 0)
			polinom = polinom + "z" + to_string(monoms[i].power % 10);
	}
}

