#include <iostream>
#include <cmath>
double f(double x){
    return pow(x,4)+ 2*pow(x,2) + 4 * x + 1; // x4+2x2+4x+1=0
}
using namespace std;
int main() {
    double a = -1, b = 0,
            a1,b1, T = 0.618,
            eps = 0.1, lam1 = 0,m1,lamY,mY, x, y;
    a1 = a;
    b1 = b;
    lam1 = a1 + (1 - T)*(b1 - a1);
    m1 = a1 + T*(b1 - a1);
    lamY = f(lam1);
    mY = f(m1);
    cout<<lamY<<endl;
    cout<< mY<< endl;
    int i = 1;
    while (b1 - a1 >= eps) {
        if (lamY > mY) {
            mY = f(m1);
            lamY = f(lam1);
            a1 = lam1;
            lam1 = m1;
            m1 = a1 + T * (b1 - a1);
            cout<<"_____________________________________________________________________________"<<endl;
            cout << "a1 = "<< a1 << "   b1 = " << b1 << " m1 = "<< m1<< " mY = "<<mY << " i= "<< i <<" lam ="<<lam1<< endl;
        }
            if (lamY < mY) {
                lamY = f(lam1);
                mY = f(m1);
                b1 = m1;
                m1 = lam1;
                lam1 = a1 + (1 - T) * (b1 - a1);
               // m1 = a1 + T * (b1 - a1);

                cout<<"_____________________________________________________________________________"<<endl;
                cout << "a1 = "<< a1 << "   b1 = " << b1 << " m1 = "<< m1<< " mY = "<<mY << " i= "<< i <<" lam ="<<lam1<< endl;
            }
        i = i + 1;
    }
    cout<<"_____________________________________________________________________________"<<endl;
    x = (a1 + b1)/2;
    y = f(x);
    cout << "x = " <<x << "  y = " << y  << endl;
        return 0;
}