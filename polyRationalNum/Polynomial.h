#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
//#include "RationalNum.h"

using namespace std;


class Polynomial
{
public:

	static const int Terms = 10;
	std::vector<int>poly;
	Polynomial();
	~Polynomial();

	void setTerm();
	int getTerm() const;
    int getTermExponet(int) const;
    int getTermCoeff(int) const;
    void setTermCoeff(int, int);

	void sort();

	void printPoly() const;

	Polynomial operator+( const Polynomial& ) const;
	Polynomial operator-( const Polynomial& ) const; 
	Polynomial operator*( const Polynomial& ) const;
	Polynomial &operator+=(const Polynomial& );
	Polynomial &operator-=(const Polynomial& );
	Polynomial &operator*=(const Polynomial& );

	friend ostream& operator<<(ostream &stream, Polynomial &poly);
	friend istream& operator>>(istream& stream, Polynomial poly);

private:
	int terms;
	int exponet[Terms];
	int coeff[Terms];
	void polyAll(Polynomial &);
	//RationalNum coefficient;
};



#endif