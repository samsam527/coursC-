#include "matrice.h"
#include <iostream>
#include <cstdlib>
using namespace std;

matrice::matrice()
{
    nbl=nbc=1;
    T= new double *[nbl];
    T[0]= new double [nbc];

}

matrice ::matrice( int nbl, int nbc)
{
    this->nbl= nbl;
    this->nbc= nbc;
    T= new double *[nbl];

    for (int i=0; i<nbl; i++)
    {
       T[i]=new double [nbc];
    }
    for (int j(0); j<nbl;j++)
        for (int k(0); k<nbc;k++)
            T[j][k] = rand()/1000.0;
}

matrice :: matrice (const matrice &A) //construteur de recopie
{
    nbl = A.nbl;
    nbc = A.nbc;
    T = new double * [nbl];
    for (int i(0);i<nbl;i++)
        T[i] = new double [nbc];
    for (int i(0); i<nbl;i++)
        for (int j(0); j< nbc;j++)
            T[i][j] = A.T[i][j];

}

matrice &matrice::operator= (const matrice &A)
{
    for (int i(0);i<nbl;i++)
        for (int j(0); j< nbc;j++)
            T[i][j] = A.T[i][j];

    return *this;
}

void matrice :: afficher () const
{
    for (int i(0);i<nbl;i++)
    {
        for (int j(0); j< nbc;j++)
            cout<< T[i][j]<< "   ";
        cout<<endl;
    }
}

double* matrice :: operator[] (int i) const
{
    return T[i];
}

matrice matrice :: operator+ (const matrice &A)
{
    matrice resultat (nbl, nbc);
    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<nbc;j++)
        {
           resultat[i][j]= A[i][j] + T[i][j];
        }
    }
    return resultat;
}
matrice matrice :: operator- (const matrice &A) const
{
    matrice resultat (nbl, nbc);
    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<nbc;j++)
        {
           resultat[i][j]= T[i][j] - A[i][j];
        }
    }
    return resultat;
}
matrice &matrice :: operator+= (const matrice &A)
{

    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<nbc;j++)
        {
           T[i][j] = T[i][j] + A[i][j];
        }
    }
    return *this;
}
matrice &matrice :: operator-= (const matrice &A)
{

    for (int i(0); i<nbl; i++)
    {
        for (int j(0); j<nbc;j++)
        {
           T[i][j] = T[i][j] - A[i][j];
        }
    }
    return *this;
}
matrice matrice :: operator* (double x)
{
    matrice A(*this);
    for (int i(0); i<nbl; i++)
        for (int j(0);j<nbc;j++)
            A[i][j]*=x;
    return A;
}

matrice matrice :: operator* (const matrice &A) const
{
    matrice B(nbl,A.nbc);
    for (int i(0); i<A.nbl; i++)
    {
        for (int j(0); j<A.nbc;j++)
        {
            B[i][j]=0;
            for (int k(0); k<A.nbc;k++)
                B[i][j] = T[i][k]*A[k][j];

        }
    }
    return B;

}

matrice& matrice:: operator*= (const matrice &A)
{
    *this=(*this)*A;
    return *this;
}

matrice& matrice:: operator*= (double x)
{
    for (int i(0); i<nbl;i++)
    {
        for(int j(0); j<nbc; j++)
            T[i][j]*=x;
    }
    return *this;
}

matrice& matrice:: operator/= (double x)
{
    *this *= 1.0/x;
    return *this;
}

matrice matrice::sousmatrice(int line_0, int col_0, int dim_nbl, int dim_nbc) const
{
    matrice A(dim_nbl,dim_nbc);
    for (int i(0); i<dim_nbl;i++)
        for (int j(0); j<dim_nbc;j++)
            A[i][j] = T[i+line_0][j+col_0];
    return A;



}
matrice matrice :: diagonale(int nbl, int nbc)
{
    matrice A(nbl,nbc);
    if (nbl != nbc)
    {
        cout<< " La matrice doit etre caree " << endl;

    }
    else
    {
    for (int i(0); i<nbl;i++)
        for (int j(0); j<nbl; j++)
            if(i == j)
                {
                    A[i][j] = T[i][j];
                }
            else
            {
                A[i][j] = 0;
            }
    }
    return A;
}
matrice::~matrice()
{
     for (int i=0; i<nbl; i++)
    {
       delete[] T[i];
    }
    delete[] T;
}
