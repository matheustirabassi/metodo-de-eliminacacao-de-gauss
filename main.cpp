#include <iostream>
#include <stdlib.h>
#include <locale>
using namespace std;

void imprimirMatriz(float **a, int lin);
float** scanearMatriz(int lin);
float **eliminacaoDeGauss(float **A, int lin);

float **eliminacaoDeGauss(float **A, int lin) {
    float **a = A;
    int n = lin;

    if(a[lin - 1][lin - 1] == 0.0) {
        exit (-1);
    }

    float m = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n ; j++) {
            m = a[j][i]/a[i][i];
            a[j][i] = 0;
            for(int k = i + 1; k < n; k++) {
                a[j][k] +=  -(m * a[i][k]);
            }
            a[j][n] += -(m * a[i][n]);
        }
    }

    return a;
}


void resolucaoMatrizSuperior(float **A, int lin) {
    float **a = A;
    int n = lin;
    float x[n];
    float s = 0;

    x[n-1] = a[n-1][n]/a[n-1][n-1];
    for(int i = n - 1; i >= 0; i--) {
        s = 0;
        for(int j = i + 1 ; j < n; j++) {
            //cout << "lin 44: " << s << " = " << s << " + " << a[i][j] << " * " << x[j] << endl;
            s += a[i][j] * x[j];
        }
        //cout << "lin 47: " << x[i] << " = (" << a[i][n] << "-" << s << ")/" << a[i][i] << endl;
        x[i] = (a[i][n] -s)/a[i][i];
    }


    cout << "---resultado---" << endl;
    for(int i = 0; i < n ; i++) {

        cout <<(char)(i + 'a') << " = " << x[i] << endl;
    }
    cout << endl;

}

void imprimirMatriz(float **a, int lin) {
    int n = lin;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + 1; j++) {
            if(j < n)
                cout << a[i][j] << char('a' + j) <<  " ";
            else
                cout << " = " << a[i][j];
        }
        cout << endl;
    }
}
float** scanearMatriz(int lin) {
    float **a = (float **) malloc(sizeof(float**) * lin);
    for(int i = 0; i < lin + 1; i++) {
        a[i] = (float *) malloc(sizeof(float *)* lin + 1);
    }
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < lin + 1; j++) {
            cin >> a[i][j];
        }
    }
    return a;
}
int main() {
    setlocale(LC_CTYPE, "");

    cout << "Bem vindo ao método de eliminação de Gauss" << endl;
    cout << "qual é a proporção da matriz? ";

    int n;
    cin >> n;
    cout << "sua matriz é " << n << "x" << n << "!" << endl;

    cout << "----equação inicial---" << endl;
    float **a = scanearMatriz(n);
    float **result = eliminacaoDeGauss(a, n);

    cout << "---equação final---" << endl;
    imprimirMatriz(result, n);
    cout << endl;

    resolucaoMatrizSuperior(result, n);

    return 0;
}
