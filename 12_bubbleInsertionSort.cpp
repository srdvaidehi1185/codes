#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// ---------------- Bubble Sort ----------------
void bubbleSort(int arr[], int n, int &comp, int &swaps) {
    for(int k = 0; k < n-1; k++) {
        for(int l = 0; l < n-k-1; l++) {
            comp++;  // count comparison
            if(arr[l] > arr[l+1]) {
                swap(arr[l], arr[l+1]);
                swaps++; // count swap
            }
        }
    }
}

// ---------------- Insertion Sort ----------------
void insertionSort(int arr[], int n, int &comp, int &swaps) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        while(prev >= 0) {
            comp++; // comparison counted

            if(arr[prev] > curr) {
                arr[prev + 1] = arr[prev];
                swaps++; // shift counted as swap
                prev--;
            }
            else break;
        }
        arr[prev + 1] = curr;
    }
}

// ---------------- Main Program ----------------
int main() {
    int n;
    cin >> n;

    int a1[100], a2[100];
    for(int i = 0; i < n; i++) {
        cin >> a1[i];
        a2[i] = a1[i];
    }

    int c1=0, s1=0, c2=0, s2=0;

    auto t1s = high_resolution_clock::now();
    bubbleSort(a1, n, c1, s1);
    auto t1e = high_resolution_clock::now();

    auto t2s = high_resolution_clock::now();
    insertionSort(a2, n, c2, s2);
    auto t2e = high_resolution_clock::now();

    cout << "Bubble Sort Comparisons: " << c1 << endl;
    cout << "Bubble Sort Swaps: " << s1 << endl;
    cout << "Bubble Sort Time: " 
         << duration_cast<microseconds>(t1e - t1s).count() << endl;

    cout << "Insertion Sort Comparisons: " << c2 << endl;
    cout << "Insertion Sort Swaps: " << s2 << endl;
    cout << "Insertion Sort Time: " 
         << duration_cast<microseconds>(t2e - t2s).count() << endl;
}
