#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int start[20], endt[20];

    cout << "Enter start and end time of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> endt[i];
    }

    // simple bubble sort by end time
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (endt[j] > endt[j+1]) {
                swap(endt[j], endt[j+1]);
                swap(start[j], start[j+1]);
            }
        }
    }

    cout << "\nSelected Activities:\n";

    cout << "Activity 1 ( " << start[0] << " , " << endt[0] << " )\n";
    int lastEnd = endt[0];

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastEnd) {
            cout << "Activity " << i+1 << " ( " << start[i] << " , " << endt[i] << " )\n";
            lastEnd = endt[i];
        }
    }
}
