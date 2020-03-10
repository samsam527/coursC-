#include <iostream>
#include "matrice.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int compteur = 0;
    matrice mat(10,10);
    matrice sousmat = mat.sousmatrice(1,2,3,3);
    sousmat.afficher();
    matrice diag = mat.diagonale(10,10);
    cout<<endl;

    diag.afficher();
    return 0;
}
