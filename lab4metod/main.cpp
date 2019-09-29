#include <iostream>
#include <cmath>
using namespace std;

float methodRectangles(float a,float b, int n){
    float h = (b - a)/n;
    float sum = 0;
    for (int i=0;i<n;i++){
        sum = exp(a + i*h + h/2) + sum;
    }
    return h*sum;
}

float methodTrapezoid(float a, float b, int n){
    float h = (b - a)/n;
    float sum = 0;
    for (int i=1;i<n;i++){
        sum += exp(a + i*h);
    }
    return h * (((exp(a) + exp(b))/2) + sum);
}

float methodSimpson(float a, float b, int n){
    float h = (b - a)/n;
    float sum = 0;
    float sum1 = 0;
    for (int i=1;i<n;i++){
        sum += exp(a + i*h);
    }
    for (int i=1;i<n+1;i++){
        sum1 += exp(a + i*h - h/2);
    }
    return h/6 * (exp(a) + exp(b) + 4 * sum1 + 2 * sum);
}

float richardson(float sum, float sum1,int k){
    return (sum - sum1) / ( pow(2,k) - 1 );
}
void integral(int k, int a, float b){
    int n = 1;
    int iterator = 0;
    float sum = 0;
    float sum1 = 0;
    float r = 9;
    while (abs(r) >=0.001){
        n *= 2;
        sum1 = sum;
        sum = methodRectangles(a,b,n);
        r = richardson(sum,sum1,k);
        iterator +=1;

    }
   cout<< iterator << endl;
   cout<< (sum) << endl;
   cout<< sum + r << endl;
}
void integral_2(int k, float a, float b){
    int n = 1;
    int iterator = 0;
    float sum = 0;
    float sum1 = 0;
    float r = 9;
    while (abs(r) >=0.001){
        n *= 2;
        sum1 = sum;
        sum = methodTrapezoid(a,b,n);
        r = richardson(sum,sum1,k);
        iterator +=1;

    }
    cout<< iterator << endl;
    cout<< (sum) << endl;
    cout<< sum + r << endl;
}
void integral_3(int k, float a, float b){
    int n = 1;
    int iterator = 0;
    float sum = 0;
    float sum1 = 0;
    float r = 9;
    while (abs(r) >=0.001){
        n *= 2;
        sum1 = sum;
        sum = methodSimpson(a,b,n);
        r = richardson(sum,sum1,k);
        iterator +=1;

    }
    cout<< iterator << endl;
    cout<< (sum) << endl;
    cout<< sum + r << endl;
}
int main() {

    float b = 1;
    float a = 0;
    cout<< "Метод 1"<< endl;
    integral(2,a,b);
    cout<< "Метод 2"<< endl;
    integral_2(2,a,b);
    cout<< "Метод 3"<< endl;
    integral_3(4,a,b);


    return 0;
}