#ifndef COMPLEXE_H
#define COMPLEXE_H
using namespace std;

class complexe
{
    public:
        double real, imag;
        complexe();
        complexe (const complexe &d);
        complexe (double real);
        complexe(double real, double imag);
        virtual~complexe();
        void afficher() const;
        complexe& operator = (const complexe &d);
        complexe  operator + (const complexe &d) const;
        complexe operator - (const complexe &d) const;
        complexe operator * (const complexe &d) const;
        complexe operator / (const complexe &d) const;
        complexe & operator += (const complexe &d);
        complexe & operator -=  (const complexe &d);
        complexe & operator *= (const complexe &d);
        complexe & operator /= (const complexe &d);
        complexe exp() const;
        complexe exp2(int N=100) const;
        complexe conj() const;
        double module() const;
        double getReal() const;
        double getImag() const;

    protected:

    private:

};

#endif // COMPLEXE_H
