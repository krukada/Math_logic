#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>

#define EPSILON 0.00001

#define C 1.0
#define B 1.0
double N = 10;

using namespace std;

double start=0,b=1;

double answer(double x){
    double C1 = (C - exp(start) - B + exp(b)) / (start-b);
    double C2 = B - exp(b) - C1*b;
    return exp(x)+C1*x+C2;
}

double p(double x){
    return 0;
}

double q(double x){
    return 0;
}

double f(double x){
    return exp(x);
}

void progonka_method(vector<double> &x,vector<double> &a,vector<double> &b,
                     vector<double> &c,vector<double> &d){
    int n = d.size();
    vector<double> alf,bet;
    alf.push_back(-c[0]/b[0]);
    bet.push_back(d[0]/b[0]);
    for(int i=1;i<n;i++){
        alf.push_back(-c[i]/(a[i-1]*alf[i-1]+b[i]));
        bet.push_back((d[i]-a[i-1]*bet[i-1])/(a[i-1]*alf[i-1]+b[i]));
    }
    x.push_back(bet[n-1]);
    double r = bet[n-1];
    for(int i=n-2;i>=0;i--){
        r = alf[i]*r+bet[i];
        x.push_back(r);
    }
    reverse(x.begin(),x.end());
}

void Progonka(vector<double> &y){
    double h = (b - start)/N;
    vector<double> d,a,b,c;

    double xi = start + h;
    b.push_back(q(xi)*h*h - 2);
    c.push_back(1 + p(xi)*h/2.0);
    d.push_back(f(xi)*h*h-C*(1-p(xi)*h/2));
    for(int i=2;i<N-1;i++){
        xi = start + i * h;
        a.push_back(1 - p(xi)*h/2.0);
        b.push_back(q(xi)*h*h - 2);
        c.push_back(1 + p(xi)*h/2.0);
        d.push_back(f(xi)*h*h);
    }
    xi = start + h * (N-1);
    b.push_back(q(xi)*h*h - 2);
    a.push_back(1 - p(xi)*h/2.0);
    d.push_back(f(xi)*h*h-B*(1+p(xi)*h/2));
    c.push_back(0);

    progonka_method(y,a,b,c,d);
}

int  main(){
    vector<double> z;
    Progonka(z);
    vector<double> y;
    y.push_back(C);
    y.reserve(N);
    y.resize(N);
    copy(z.begin(),z.end(),y.begin()+1);
    y.push_back(B);

    double F=0,h=(b-start)/N;
    cout.precision(8);
    cout<<"Вычисленные значения: ";
    for(int i=0;i<N+1;i++){
        cout<<y[i]<<" ";
    }
    cout<<endl;
    cout<<"Достоверное решение: ";
    for(int i=0;i<N+1;i++){
        cout<<answer(start+i*h)<<" ";
    }
    cout<<endl;
    for(int i=0;i<N+1;i++){
        F+=abs(y[i]-answer(start+i*h))*abs(y[i]-answer(start+i*h));
    }
    cout<<"Средний квадрат отклонения: "<<F/(N+1)<<endl;
    return 0;
}