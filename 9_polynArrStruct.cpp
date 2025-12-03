#include <iostream>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

int main() {
    Term A[10], B[10], C[20];
    int n1, n2, k = 0;

    cout << "Enter number of terms in 1st polynomial: ";
    cin >> n1;
    cout << "Enter coeff and exp:\n";
    for (int i = 0; i < n1; i++)
        cin >> A[i].coeff >> A[i].exp;

    cout << "Enter number of terms in 2nd polynomial: ";
    cin >> n2;
    cout << "Enter coeff and exp:\n";
    for (int i = 0; i < n2; i++)
        cin >> B[i].coeff >> B[i].exp;

    // ------------------- Addition -------------------
    cout << "\nAddition: ";
    int i = 0, j = 0;
    k = 0;
    while (i < n1 && j < n2) {
        if (A[i].exp == B[j].exp) {
            C[k].coeff = A[i].coeff + B[j].coeff;
            C[k].exp = A[i].exp;
            i++; j++; k++;
        } else if (A[i].exp > B[j].exp) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }
    while (i < n1) C[k++] = A[i++];
    while (j < n2) C[k++] = B[j++];

    for (int t = 0; t < k; t++)
        cout << C[t].coeff << "x^" << C[t].exp << " ";

    // ------------------- Multiplication -------------------
    cout << "\nMultiplication: ";
    int m = 0;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            C[m].coeff = A[i].coeff * B[j].coeff;
            C[m].exp = A[i].exp + B[j].exp;
            m++;
        }
    }

    for (int t = 0; t < m; t++)
        cout << C[t].coeff << "x^" << C[t].exp << " ";

    return 0;
}