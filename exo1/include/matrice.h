#ifndef MATRICE_H
#define MATRICE_H


class matrice
{
    public:
        matrice();
        matrice(int nbl, int nbc);
        matrice (const matrice &A);
        matrice& operator= (const matrice &A);
        matrice operator+ (const matrice &A);
        matrice operator- (const matrice &A);
        matrice& operator*= (double x) ;
        matrice operator/ (double x) const;
        matrice operator* (const matrice &A) const;
        matrice operator- (const matrice &A) const;
        double* operator[] (int i) const;
        matrice& operator+= (const matrice &A);
        matrice& operator-= (const matrice &A);
        matrice& operator*= (const matrice &A);
        matrice& operator/= (double x);
        matrice operator* (double x);
        void afficher() const;
        matrice sousmatrice(int line_0, int col_0, int nbl, int nbc) const;
        matrice diagonale(int nbl, int nbc) ;
        virtual ~matrice();

    protected:

    private:
        double **T;
        int nbl, nbc;
};

#endif // MATRICE_H
