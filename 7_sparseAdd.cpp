#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

// Add two sparse matrices
void addSparse(Term A[], Term B[], Term C[]) {
    int i = 1, j = 1, k = 1;

    // header for result
    C[0].row = A[0].row;
    C[0].col = A[0].col;
    C[0].val = 0;  // count later

    while (i <= A[0].val && j <= B[0].val) {
        // If A's term comes first
        if (A[i].row < B[j].row ||
           (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        // If B's term comes first
        else if (B[j].row < A[i].row ||
                (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        // Same row & col → add values
        else {
            C[k] = A[i];
            C[k].val = A[i].val + B[j].val;
            k++; i++; j++;
        }
    }

    // Copy remaining A terms
    while (i <= A[0].val) C[k++] = A[i++];

    // Copy remaining B terms
    while (j <= B[0].val) C[k++] = B[j++];

    C[0].val = k - 1; // update count
}

// Print 3-tuple
void print(Term T[]) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= T[0].val; i++)
        cout << T[i].row << "   " << T[i].col << "   " << T[i].val << endl;
}

int main() {
    // Example matrices
    Term A[10] = {
        {3, 3, 3},   // rows, cols, non-zero
        {0, 0, 5},
        {1, 2, 7},
        {2, 1, 6}
    };

    Term B[10] = {
        {3, 3, 2},
        {0, 0, 3},
        {2, 2, 4}
    };

    Term C[20];

    addSparse(A, B, C);

    cout << "Result of Addition:\n";
    print(C);

    return 0;
}
