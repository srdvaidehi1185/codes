#include <iostream>
using namespace std;

// Function to add two polynomials
void addPoly(int A[], int B[], int C[], int n) {
    for (int i = 0; i < n; i++)
        C[i] = A[i] + B[i];
}

// Function to multiply two polynomials
void multiplyPoly(int A[], int B[], int C[], int n) {
    for (int i = 0; i < 2*n - 1; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i + j] += A[i] * B[j];
}

int main() {
    int n = 3;   // degree 2 polynomial (0,1,2)

    int A[3] = {2, 5, 3};  // 3x² + 5x + 2
    int B[3] = {1, 2, 4};  // 4x² + 2x + 1

    int Add[3], Mul[5];

    addPoly(A, B, Add, 3);
    multiplyPoly(A, B, Mul, 3);

    cout << "Addition: ";
    for (int i = 0; i < 3; i++)  cout << Add[i] << " ";
    cout << "\n";

    cout << "Multiplication: ";
    for (int i = 0; i < 5; i++)  cout << Mul[i] << " ";
}