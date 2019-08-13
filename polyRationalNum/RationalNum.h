#ifndef RATIONALNUM_H
#define RATIONALNUM_H

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class RationalNum 
{
	int numer;
	int denom;
	void reduce();
	int coefficient;

public:
	RationalNum(int = 0, int = 1);
	~RationalNum(){};
	friend ostream& operator<<(ostream &stream, const RationalNum &rhs);
	friend istream& operator>>(istream &stream,  RationalNum &rhs);

	RationalNum operator+(const RationalNum &a) const;
	RationalNum operator-(const RationalNum &s) const; 
	RationalNum operator*(const RationalNum &m) const;
	RationalNum operator/(const RationalNum &v) const;

};


RationalNum::RationalNum(int n, int d)
{
	numer = n;
	denom = d;
}

void RationalNum::reduce()
{
	int temp;

	temp = numer > denom ? numer : denom;
	int gcd = 0;
	for(int i = 2; i<=temp; i++)
		if(numer % i == 0 && denom % i ==0)
			gcd = i;
	if(gcd != 0)
	{
		numer /= gcd;
		denom /= gcd;
	}
}

istream &operator>>(istream &in, RationalNum &rhs)
{
	char s = '/';
	in>>rhs.numer>>s;
	if(s != 0)
	in>>rhs.denom;
	in>>rhs.coefficient;

	return in;
}

ostream &operator<<(ostream &out, const RationalNum &rhs)
{
	if(rhs.denom == 1)
		out<<rhs.numer;
	else
		out<<rhs.numer<<"/"<<rhs.denom;
	return out;
}


RationalNum RationalNum::operator+(const RationalNum &a) const
{
	int n = (numer * a.denom) + (a.numer * denom);
	int d = (denom * a.denom);
	RationalNum sum(n, d);
	sum.reduce();
	return sum;

}

RationalNum RationalNum::operator-(const RationalNum &s) const
{
	int n = (numer * s.denom) - (s.numer * denom);
	int d = (denom * s.denom);
	RationalNum sub(n, d);
	sub.reduce();
	return sub;
	
}

RationalNum RationalNum::operator*(const RationalNum &m) const
{
	int n = (numer * m.numer);
	int d = (denom * m.denom);
	RationalNum mult(n, d);
	mult.reduce();
	return mult;
}

RationalNum RationalNum::operator/(const RationalNum &v) const
{
	int n = (numer * v.denom) ;
	int d = (denom * v.numer);
	RationalNum div(n, d);
	div.reduce();
	return div;
}


#endif