#include "complexe.h"
#include <iostream>
#include <math.h>
using namespace std;
complexe::complexe()
{
    //ctor
    real = 0;
    imag = 0;

}
complexe::complexe(double real)
{
    //ctor
    this -> real = real;
    imag = 0;

}
complexe:: complexe(double real, double imag)
{
    this -> real = real;
    this -> imag = imag;
}
void complexe :: afficher() const
{
    if (real != 0 || imag == 0)
    {
        cout <<real;
    }
    if (imag != 0)
    {
       if (imag >0 && real !=0)
       {
           cout << "+";
       }
       if (imag < 0)
       {
           cout << "-";
       }
       double a(imag);
       if(a< 0)
       {
           a *= -1;
       }
       if (a !=1)
       {
            cout << a;
        }
            cout <<"i";
    }
}
complexe:: complexe(const complexe & d)
{
    real = d.real;
    imag = d.imag;
}
complexe & complexe :: operator = (const complexe &d)
{
    real = d.real;
    imag = d.imag;
    return *this;
}
complexe complexe :: operator + (const complexe &d) const
{
    complexe r(d); // appele operateur recopié
    r.real += real;
    r.imag += imag;
    return r;
}
complexe complexe :: operator - (const complexe &d) const
{
    complexe r(*this);
    r.real -= d.real;
    r.imag -= d.imag;
    return r;
}

complexe complexe :: operator * (const complexe &d) const
{
    complexe r(real*d.real - imag*d.imag, real*d.imag + imag*d.real);
    return r;

}
double complexe :: getReal() const
{
    return real;
}
double complexe :: getImag() const
{
    return imag;

}
complexe complexe :: conj() const
{
    complexe r(real, -imag);
    return r;
}

double complexe :: module () const
{
    return sqrt(real*real + imag*imag);
}
complexe & complexe :: operator += (const complexe &d)
{
    real= d.getReal();
    imag=d.getImag();
    return *this;

}
complexe & complexe :: operator -=  (const complexe &d)
{
    real = d.getReal();
    imag = d.getImag();
    return *this;
}

complexe & complexe  :: operator *= (const complexe &d)
{
    complexe r = (*this)*d;
    *this = r;
    return *this;
}

complexe & complexe :: operator /= (const complexe &d)
{
    *this = (*this)/d;
    return *this;
}
complexe complexe :: exp() const
{
    complexe r = complexe (cos(imag), sin(imag))*::exp(real);//mettre 2 points pour pas qu'il confonde exp math
    return r;
}
complexe complexe :: exp2(int N) const
{
    complexe tmp(1);
    complexe r = tmp;
    for(int k =1; k<=N;k++)
    {
        tmp *= (*this)/k;
        r += tmp;
    }
    return r;
}



complexe complexe :: operator / (const complexe &d) const
{
    complexe a = (*this)*d.conj();
    double m=d.module();
    m*=m;
    a.real/=m;
    a.imag/=m;
    return a;

}
complexe::~complexe()
{
    //dtor
}
