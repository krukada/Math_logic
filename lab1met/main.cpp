#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Длина матрицы " << endl;
    cin >> n;

    float *a = new float [n-1];
    float *b = new float [n];
    float *c = new float [n-1];
    float *d = new float [n];

    cout << "Главная диагональ" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << "Диагональ слева от главной" << endl;
    for (int i = 0; i < n-1; i++) {
        cin >> c[i];
    }
    cout << "Диагональ справа от главной" << endl;
    for (int i = 0; i < n-1; i++) {
        cin >> a[i];
    }
    cout << "Введите вектор d" << endl;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
// Угловое диагональное приближение
    for (int i = 2; i < n; i++) {
        if (abs(b[i]) < abs(a[i - 1]) + abs (c[i])) {
            cout << "Ошибка" << endl;
            return 0;
        }
        if (abs(a[i - 1])/abs(b[i]) > 1) {
            cout << "Ошибка" << endl;
            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (abs(c[i])/abs(b[i]) > 1) {
            cout << "Ошибка" << endl;
            return 0;
        }
    }
//ПХМП

    float *alpha = new float [n];
    float *beta = new float [n];
    float *x = new float [n];
    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            if (b[i] == 0) {
                cout << "Ошибка" << endl;
                return 0;
            }
            else {
                alpha[i] = -c[i]/b[i];
                beta[i] = d[i]/b[i];
            }
        }
        else {
            if ((a[i-1]*alpha[i-1] + b[i]) == 0) {
                cout << "Ошибка" << endl;
                return 0;
            }
            else {
                alpha[i] = -c[i]/(a[i-1]*alpha[i-1] + b[i]);
                beta[i] = (d[i] - a[i-1]*beta[i-1])/(a[i-1]*alpha[i-1] + b[i]);
            }
        }
    }

    if ((a[n-2]*alpha[n-2] + b[n-1]) == 0) {
        cout << "Ошибка" << endl;
        return 0;
    }
    // OXMP

    x[n-1] = (d[n-1] - a[n-2]*beta[n-2])/(a[n-2]*alpha[n-2] + b[n-1]);
    for (int i = n-2; i >= 0; i--) {
        x[i] = alpha[i]*x[i + 1] + beta [i];
    }

    cout << "Значение:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i << " = " << x[i] << endl;
    }

    delete [] a;
    delete [] b;
    delete [] c;
    delete [] d;
    delete [] alpha;
    delete [] beta;
    delete [] x;

    return 0;
}
