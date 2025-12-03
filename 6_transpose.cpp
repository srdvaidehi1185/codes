#include <iostream>
using namespace std;

// Structure for 3-tuple
struct Term {
    int row, col, val;
};

// Simple Transpose
void simpleTranspose(Term a[], Term b[]) {
    int k = 1;  // index for b
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    for (int c = 0; c < a[0].col; c++) {
        for (int i = 1; i <= a[0].val; i++) {
            if (a[i].col == c) {
                b[k].row = a[i].col;
                b[k].col = a[i].row;
                b[k].val = a[i].val;
                k++;
            }
        }
    }
}

// Fast Transpose
void fastTranspose(Term a[], Term b[]) {
    int m = a[0].row;
    int n = a[0].col;
    int t = a[0].val;

    b[0].row = n;
    b[0].col = m;
    b[0].val = t;

    int rowCount[100] = {0};
    int startPos[100] = {0};

    // Count how many non-zero values in each column
    for (int i = 1; i <= t; i++)
        rowCount[a[i].col]++;

    // Find starting position of each column in output
    startPos[0] = 1;
    for (int i = 1; i < n; i++)
        startPos[i] = startPos[i-1] + rowCount[i-1];

    // Fill fast transpose
    for (int i = 1; i <= t; i++) {
        int pos = startPos[a[i].col]++;
        b[pos].row = a[i].col;
        b[pos].col = a[i].row;
        b[pos].val = a[i].val;
    }
}

// Print matrix in 3-tuple form
void print(Term a[]) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= a[0].val; i++)
        cout << a[i].row << "   " << a[i].col << "   " << a[i].val << endl;
}

int main() {
    // Example sparse matrix in 3-tuple
    // 3 rows, 3 cols, 3 non-zero values
    Term a[10] = {
        {3, 3, 3},  // (rows, cols, non-zero)
        {0, 0, 5},
        {1, 2, 8},
        {2, 1, 6}
    };

    Term b1[10], b2[10];

    simpleTranspose(a, b1);
    fastTranspose(a, b2);

    cout << "Simple Transpose:\n";
    print(b1);

    cout << "\nFast Transpose:\n";
    print(b2);

    return 0;
}
