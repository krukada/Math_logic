#include <iostream>
#include <cmath>

using namespace std;
double r(double value, int k){
    return round((pow(10, k)*value))/pow(10, k);
}

double f(double x, double y, double z){
    return (exp(x) + y - z);
}
double g(double x, double y, double z){
    return (z);
}
void Kutta(double h, double h2){

    int k = 2;
    double Xo, Yo, Y1, Zo, Z1;
    double k1, k2, k4, k3;
    double q1, q2, q4, q3;
    double Xo_2, Yo_2, Y1_2, Zo_2, Z1_2;
    double k1_2, k2_2, k4_2, k3_2;
    double q1_2, q2_2, q4_2, q3_2;

    Xo = 0.1;
    Yo = 1.0;
    Zo = 1.0;
    cout<< "\tX\t\tY\t\tZ" << endl;
    for(; r(Xo,2)<1.0; Xo += h){

        k1 = h * f(Xo, Yo, Zo);
        q1 = h * g(Xo, Yo, Zo);

        k2 = h * f(Xo + h/2.0, Yo + q1/2.0, Zo + k1/2.0);
        q2 = h * g(Xo + h/2.0, Yo + q1/2.0, Zo + k1/2.0);

        k3 = h * f(Xo + h/2.0, Yo + q2/2.0, Zo + k2/2.0);
        q3 = h * g(Xo + h/2.0, Yo + q2/2.0, Zo + k2/2.0);

        k4 = h * f(Xo + h, Yo + q3, Zo + k3);
        q4 = h * g(Xo + h, Yo + q3, Zo + k3);

        Z1 = Zo + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
        Y1 = Yo + (q1 + 2.0*q2 + 2.0*q3 + q4)/6.0;
        cout<< "\t" << r(Xo + h , k) << "\t\t" << Y1<< "\t\t" << Z1 << endl;

        Yo = Y1;
        Zo = Z1;

    }

    Xo_2 = 0;
    Yo_2 = 1.0;
    Zo_2 = 1.0;

    for(; r(Xo_2,2)<1.0; Xo_2 += h2){

        k1_2 = h2 * f(Xo_2, Yo_2, Zo_2);
        q1_2 = h2 * g(Xo_2, Yo_2, Zo_2);

        k2_2 = h2 * f(Xo_2 + h2/2.0, Yo_2 + q1_2/2.0, Zo_2 + k1_2/2.0);
        q2_2 = h2 * g(Xo_2 + h2/2.0, Yo_2 + q1_2/2.0, Zo_2 + k1_2/2.0);

        k3_2 = h2 * f(Xo_2 + h2/2.0, Yo_2 + q2_2/2.0, Zo_2 + k2_2/2.0);
        q3_2 = h2 * g(Xo_2 + h2/2.0, Yo_2 + q2_2/2.0, Zo_2 + k2_2/2.0);

        k4_2 = h2 * f(Xo_2 + h2, Yo_2 + q3_2, Zo_2 + k3_2);
        q4_2 = h2 * g(Xo_2 + h2, Yo_2 + q3_2, Zo_2 + k3_2);

        Z1_2 = Zo_2 + (k1_2 + 2.0*k2_2 + 2.0*k3_2 + k4_2)/6.0;
        Y1_2 = Yo_2 + (q1_2 + 2.0*q2_2 + 2.0*q3_2 + q4_2)/6.0;
        cout<< "\t" << r(Xo_2+h2, k) << "\t\t" << Y1_2<< "\t\t" << Z1_2 << endl;
        Yo_2 = Y1_2;
        Zo_2 = Z1_2;
    }
}
int main() {



    double h;

    h = 0.1;
    Kutta(h,0.05);

    return 0;
}