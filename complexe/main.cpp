#include <iostream>
#include "complexe.h"

using namespace std;


int main()
{
    /*
    cout << "Hello world!" << endl;
    complexe a;
    cout << "a = ";
    a.afficher();
    cout<<endl;

    complexe b(0,-7);
    cout << "b = " ;
    b.afficher();
    cout<<endl;

    complexe c(2,3);
    cout << "c = " ;
    c.afficher();
    cout<<endl;

    complexe d(1,2);
    cout << "d = " ;
    d.afficher();
    cout<<endl;

    complexe e (d);
    cout << "e = ";
    e.afficher();
    cout <<endl;
    // <=> b = d <=> d.operator=(b)
    //d=b=c; <=> d=b; d=c
    complexe f(d+b); //<=> a.operator(b)
    cout << "f = ";
    f.afficher();
    cout<<endl;

    complexe g(d-b);
    cout <<"g = ";
    g.afficher();
    cout<<endl;

    complexe h (d*b);
    cout <<"h = ";
    h.afficher();
    cout<<endl;

    complexe z (b*d + h - e);
    cout <<"z = ";
    z.afficher();
    cout<<endl;
    complexe v = f/c;
    cout << "v = " ;
    v.afficher();
    cout<<endl;

    complexe y(1,2);
    complexe x= d.exp2(200); // f.exp2(100)
    cout << "x = " ;
    x.afficher();
    cout<<endl;

    complexe q = d.exp();
    cout << "x = " ;
    q.afficher();
    cout<<endl;
*/
    int N = 100;
    int * tab_1 = new int [N];
    complexe * tabC = new complexe[N];
    delete[] tab_1;
    delete[] tabC;
    return 0;

}
