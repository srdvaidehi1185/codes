#include <iostream>
using namespace std;

// -------------------------- BINARY SEARCH --------------------------
int binarySearch(int arr[], int key, int size, int &comp) {
    int low = 0, high = size - 1;

    while (low <= high) {
        comp++;  // counting comparison
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return -1;
}

// -------------------------- MIN FUNCTION --------------------------
int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// ----------------------- FIBONACCI SEARCH -------------------------
int fibonacciSearch(int arr[], int key, int size, int &comp) {

    int fibMm2 = 0;     // (m-2)
    int fibMm1 = 1;     // (m-1)
    int fibM   = fibMm1 + fibMm2;   // m

    // create smallest Fibonacci number >= size
    while (fibM < size) {
        comp++;
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM   = fibMm1 + fibMm2;
    }

    int offset = -1;

    while (fibM > 1) {
        comp++;
        int i = minVal(offset + fibMm2, size - 1);

        if (arr[i] < key) {
            fibM  = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;
            offset = i;
        }
        else if (arr[i] > key) {
            fibM   = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        }
        else {
            return i;
        }
    }

    comp++;
    if (fibMm1 && offset + 1 < size && arr[offset + 1] == key)
        return offset + 1;

    return -1;
}

// --------------------------- MAIN PROGRAM --------------------------
int main() {
    int arr[50], n, key, pos, comp = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    pos = binarySearch(arr, key, n, comp);
    cout << "Binary Search comparisons = " << comp << endl;

    comp = 0; 
    pos = fibonacciSearch(arr, key, n, comp);
    cout << "Fibonacci Search comparisons = " << comp << endl;

    return 0;
}
