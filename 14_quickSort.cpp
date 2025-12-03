#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int comparisons = 0;
int swapsCount = 0;

// --------------------------------------------------
// PARTITION FUNCTION (your same function, just counted)
// --------------------------------------------------
int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = 0;

    // Count how many elements ≤ pivot
    for (int i = s + 1; i <= e; i++) {
        comparisons++;
        if (arr[i] <= pivot) {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;

    swap(arr[pivotIndex], arr[s]);
    swapsCount++;

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] < pivot) {
            comparisons++;
            i++;
        }

        while (arr[j] > pivot) {
            comparisons++;
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            swapsCount++;
        }
    }
    return pivotIndex;
}

// --------------------------------------------------
// QUICK SORT FUNCTION
// --------------------------------------------------
void quickSort(int arr[], int s, int e) {
    if (s >= e) return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {
    int n, arr[100];
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();

    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nComparisons: " << comparisons;
    cout << "\nSwaps: " << swapsCount;

    cout << "\nTime: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    return 0;
}
