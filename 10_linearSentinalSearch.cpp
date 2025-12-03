#include <iostream>
using namespace std;

// ---------------- Linear Search ----------------
int linearSearch(int arr[], int size, int key, int &comp) {
    comp = 0;
    for (int i = 0; i < size; i++) {
        comp++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ---------------- Sentinel Search ----------------
int sentinelSearch(int arr[], int size, int key, int &comp) {
    comp = 0;

    int last = arr[size - 1];
    arr[size - 1] = key;

    int i = 0;
    while (true) {
        comp++;                    // count comparison
        if (arr[i] == key)
            break;
        i++;
    }

    arr[size - 1] = last;

    if (i < size - 1 || last == key)
        return i;

    return -1;
}


// ---------------- MAIN (SMALL & SIMPLE) ----------------
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = 9;
    int key = 6;
    int choice, comp, position = -1;

    cout << "Enter choice (1 = Linear, 2 = Sentinel): ";
    cin >> choice;

    if (choice == 1)
        position = linearSearch(arr, size, key, comp);
    else if (choice == 2)
        position = sentinelSearch(arr, size, key, comp);
    else {
        cout << "Invalid choice\n";
        return 0;
    }

    if (position != -1)
        cout << "Element found at index " << position << endl;
    else
        cout << "Element not found\n";

    cout << "Comparisons = " << comp << endl;

    return 0;
}
