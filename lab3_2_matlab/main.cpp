#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int n;

    float x[9] = {1, 1.5, 2, 2.5,3, 3.5, 4, 4.5,5};
    float y[9] = {3.33, 3.81, 4.72, 6.18, 6.63, 7.52, 9.16, 10.36,10.95};


    float yg = sqrt(y[0] * y[sizeof(y)/ sizeof(y[0]) - 1]);
    float yh = 2 * (y[0] * y[sizeof(y)/ sizeof(y[0]) - 1]) / (y[0] + y[sizeof(y)/ sizeof(y[0]) - 1]);
    float ya = (y[0] + y[sizeof(y)/ sizeof(y[0]) - 1]) / 2;
    cout << ya << endl;
    cout << yh << endl;
    cout << yg << endl;
    float xa = log(ya)/log(2.0);
    float xh = log(yh)/log(2.0);
    float xg = log(yg)/log(2.0);
    cout << "XA" << endl;
    cout << xa << endl;
    cout << "XH" << endl;
    cout << xh << endl;
    cout << "XG" << endl;
    cout << xg << endl;
    float *delta = new float [9];

    delta[0] = abs(ya - y[int(xa * 2) - 1]);
    delta[1] = abs(yg - y[int(xg * 2) - 1]);
    delta[2] = abs(yg - y[int(xa * 2) - 1]);
    delta[3] = abs(ya - y[int(xg * 2) - 1]);
    delta[4] = abs(ya - y[int(xh * 2) - 1]);
    delta[5] = abs(yh - y[int(xa * 2) - 1]);
    delta[6] = abs(yh - y[int(xh * 2) - 1]);
    delta[7] = abs(yg - y[int(xh * 2) - 1]);
    delta[8] = abs(yh - y[int(xg * 2) - 1]);

    for  (int i = 0; i < 9; i++){
        cout << delta[i]<< endl;
    }
    float *yy = new float [9];
    float *xx = new float [9];

    for  (int i = 0; i < 9; i++){
        yy[i] = log(y[i]);
        xx[i] = 1/x[i];
    }




    float sX,sY,sXX,sXY;
    for (int i=0;i<9;i++){
        sX = xx[i] + sX;
        sY = yy[i] + sY;
        sXX = xx[i] * xx[i] + sXX;
        sXY = xx[i] * yy[i] + sXY;

    }


    float aa = (sXY * 9 - sY * sX)/(9 * sXX - sX * sX);
    float bb = (sY - aa * sX)/9;
    cout << "BB, AA" << endl;

    float b = aa;
    float a = exp(bb);
    cout << "B" << endl;
    cout << b << endl;
    cout << "A" << endl;
    cout << a << endl;

}