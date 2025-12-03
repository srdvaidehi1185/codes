#include <iostream>
using namespace std;

// Insert operation
void insertElement(int arr[], int &n, int pos, int value) {
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
}

// Delete operation
void deleteElement(int arr[], int &n, int pos) {
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

// Merge operation
void mergeArrays(int a[], int n, int b[], int m, int c[]) {
    for (int i = 0; i < n; i++) c[i] = a[i];
    for (int i = 0; i < m; i++) c[n + i] = b[i];
}

int main() {

    // -------------------- 2D USING 1D ARRAY --------------------
    int rows = 2, cols = 3;
    int A[6] = {1, 2, 3, 4, 5, 6};

    cout << "2D Array simulated using 1D (Row-Major):\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = r * cols + c;  // row-major formula
            cout << A[index] << " ";
        }
        cout << endl;
    }

    cout << "\n2D Array simulated using 1D (Column-Major):\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = c * rows + r;  // column-major formula
            cout << A[index] << " ";
        }
        cout << endl;
    }

    // -------------------- POINTER ADDRESSES --------------------
    cout << "\nMemory addresses using pointer arithmetic:\n";
    for (int i = 0; i < 6; i++) {
        cout << "A[" << i << "] = " << A[i]
             << " stored at " << (A + i) << endl;
    }

    // -------------------- INSERT, DELETE, MERGE --------------------
    int arr[20] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    // Insert
    insertElement(arr, n, 2, 99);
    cout << "\nAfter insertion (insert 99 at pos 2): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    // Delete
    deleteElement(arr, n, 3);
    cout << "\nAfter deletion (delete pos 3): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    // Merge
    int arr2[5] = {5, 6, 7, 8, 9};
    int merged[20];

    mergeArrays(arr, n, arr2, 5, merged);

    cout << "\nMerged array: ";
    for (int i = 0; i < n + 5; i++) cout << merged[i] << " ";

    cout << endl;
    return 0;
}
