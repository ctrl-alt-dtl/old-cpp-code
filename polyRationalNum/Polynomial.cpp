#include "stdafx.h"
#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
	for(int i = 0; i < Terms; i++)
   {
      exponet[i] = 0;
	  coeff[i] = 0;
   } 
   terms = 0;
}

Polynomial Polynomial::operator+( const Polynomial& rhs) const
{
Polynomial PolyResult;

   bool exponetExists;
   int s;

   PolyResult.coeff[0] = coeff[0] + rhs.coeff[0];
  
   for(s = 1; (s < Terms) && (rhs.exponet[s] != 0); s++)
   {
      PolyResult.coeff[s] = rhs.coeff[s];
      PolyResult.exponet[s] = rhs.exponet[s];
   }
   for(int x = 1; x < Terms; x++)
   {
      exponetExists = false;
      
      for(int t = 1; (t < Terms) && (!exponetExists); t++)
        if(exponet[x] == PolyResult.exponet[t])
        {
           PolyResult.coeff[t] += coeff[x];
           exponetExists = true; 
        } 
      if(!exponetExists)
      {
         PolyResult.exponet[s] = exponet[x];
         PolyResult.coeff[s] += coeff[x];
         s++;
      } 
   } 
return PolyResult;
}

Polynomial Polynomial::operator-(const Polynomial &rhs) const // subtraction
{
   Polynomial PolyResult;
   bool expExists;
   int s;
   
   
   PolyResult.coeff[0] = coeff[0] - rhs.coeff[0];
   
   for(s = 1; (s < Terms) && (exponet[s] != 0); s++)
   {
      PolyResult.coeff[s] = coeff[s];
      PolyResult.exponet[s] = exponet[s];
   } 
   for (int x = 1; x < Terms; x++)
   {
      expExists = false;
      
      for(int t = 1; (t < Terms) && (!expExists); t++)
      
        if(rhs.exponet[x] == PolyResult.exponet[t])
        {
           PolyResult.coeff[t] -= rhs.coeff[x];
           expExists = true;
        }
      if(!expExists)
      {
         PolyResult.exponet[s] = rhs.exponet[x];
         PolyResult.coeff[s] -= rhs.coeff[x];
         s++;
      }
   }
return PolyResult;
}

Polynomial Polynomial::operator*(const Polynomial& rhs) const
{
   Polynomial PolyResult;
   int s = 1;
   
   for(int x = 0; (x < Terms) && (x == 0 || coeff[x] != 0); x++)
   
           for(int y = 0; (y < Terms) && (y == 0 || rhs.coeff[y] != 0); y ++)
           
                   if(coeff[x] * rhs.coeff[y])
                   
                     if((exponet[x] == 0) && (rhs.exponet[y] == 0))
                       PolyResult.coeff[0] += coeff[x] * rhs.coeff[y];
                     else
                     {
                        PolyResult.coeff[s] = coeff[x] * rhs.coeff[y];
                        PolyResult.exponet[s] = exponet[x] + rhs.exponet[y];
                        s++;
                     }
   //polyCombine(PolyResult);
   return PolyResult;
}

Polynomial &Polynomial::operator+=(const Polynomial& rhs)
{
	*this = *this + rhs;
	return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial& rhs)
{
   *this = *this - rhs;
   return *this;
} 

Polynomial &Polynomial::operator*=(const Polynomial& rhs)
{
   *this = *this * rhs;
   return *this;
}

void Polynomial::setTerm()
{
   bool found = false;
   int a, b, term;
   
   cout << endl << "Enter number of terms: ";
   cin >> terms;
   
   for(int n = 0; n < Terms && n < terms; n++)
   {
      cout << endl << "Enter coefficient (a/b): ";
      cin >> a;
      cout << "Enter exponetonent: ";
      cin >> b;
      
      if(a != 0)
      {
         if(b == 0)
         {
            coeff[0] += a;
            continue;
         }
         for(term = 1; (term < Terms) && (coeff[term] !=0); term++)
         
           if(b == exponet[term])
           {
              coeff[term] += a;
              exponet[term] = b;
              found = true; 
           }
         if(!found)
         {
            coeff[term] += a;
            exponet[term] = b;
         } 
      } 
   } 
} 

void Polynomial::printPoly() const
{
   int start;
   bool zero = false;
   
   if(coeff[0])
   {
      cout << coeff[0];
      start = 1;
      zero = true;
   }
   else
   {
       if(coeff[1])
       {
          cout << coeff[1] << 'x';
          if((exponet[1] != 0) && (exponet[1] != 1))
            cout << '^' << exponet[1];
          zero = true;
       } 
       start = 2;
   } 
   
   for(int x = start; x < Terms; x++)
   {
      if(coeff[x] != 0)
      {
         cout << showpos << coeff[x] << noshowpos << 'x';
         
         if((exponet[x] != 0) && (exponet[x] != 1))
           cout << '^' << exponet[x];
         
         zero = true; 
      }
   }
   if(!zero)
     cout << '0';
     cout << endl;
}
 
int Polynomial::getTerm() const
{
   return Terms;     
}

int Polynomial::getTermExponet(int term) const
{
   return exponet[Terms];
}

int Polynomial::getTermCoeff(int term) const
{
   return coeff[Terms];
}

void Polynomial::setTermCoeff(int term, int coeffs)
{
   if(coeff[Terms] == 0)
     cout << "No term at this location, cannot see term." << endl;
   else 
     coeff[Terms] = coeffs;
}

void Polynomial::polyAll(Polynomial &p)
{
   Polynomial PolyResult = p;
   
   for(int x = 0; x < Terms; x++)
   {
      p.coeff[x] = 0;
      p.exponet[x] = 0;
   }
   for(int x = 1; x < Terms; x++)
   {
      for(int y = x + 1; y < Terms; y++)
        if(PolyResult.exponet[x] == PolyResult.exponet[y])
        {
           PolyResult.coeff[x] += PolyResult.coeff[y];
           PolyResult.exponet[y] = 0;
           PolyResult.coeff[y] = 0;
        }
   }
   p = PolyResult;
}
Polynomial::~Polynomial()
{
   // empty
}



