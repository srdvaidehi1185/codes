#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// ------------------- SHELL SORT -------------------
void shellSort(int arr[], int n, int &comp, int &swaps) {
    for(int gap = n/2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while(j >= gap) {
                comp++; 
                if(arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                } else break;
            }
            arr[j] = temp;
        }
    }
}

// ------------------- RADIX SORT FUNCTIONS -------------------
int getMax(int arr[], int n) {
    int mx = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp, int &comp, int &swaps) {
    int output[100];    
    int count[10] = {0};

    for(int i=0; i<n; i++)
        count[(arr[i]/exp)%10]++;

    for(int i=1; i<10; i++)
        count[i] += count[i-1];

    for(int i=n-1; i>=0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
        swaps++;  
    }
}

void radixSort(int arr[], int n, int &comp, int &swaps) {
    int max = getMax(arr, n);
    for(int exp=1; max/exp > 0; exp *= 10)
        countSort(arr, n, exp, comp, swaps);
}

// ------------------- MAIN (Super Simple) -------------------
int main() {

    int arr[] = {90, 45, 170, 75, 802, 24, 2, 66};
    int arr2[8];
    for(int i=0;i<8;i++) arr2[i] = arr[i];  // copy array

    int compS = 0, swapsS = 0;
    int compR = 0, swapsR = 0;

    auto t1 = high_resolution_clock::now();
    shellSort(arr, 8, compS, swapsS);
    auto t2 = high_resolution_clock::now();

    auto t3 = high_resolution_clock::now();
    radixSort(arr2, 8, compR, swapsR);
    auto t4 = high_resolution_clock::now();

    cout << "\nShell Sort: ";
    for(int x : arr) cout << x << " ";
    cout << "\nTime: " << duration_cast<microseconds>(t2 - t1).count()
         << "  Comparisons: " << compS << "  Swaps: " << swapsS;

    cout << "\n\nRadix Sort: ";
    for(int x : arr2) cout << x << " ";
    cout << "\nTime: " << duration_cast<microseconds>(t4 - t3).count()
         << "  Comparisons: " << compR << "  Swaps: " << swapsR;

    return 0;
}
