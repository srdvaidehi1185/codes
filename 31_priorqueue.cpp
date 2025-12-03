#include <iostream>
using namespace std;

#define SIZE 10

int pq[SIZE];
int n = 0;   // number of elements

// Insert element in sorted order (smallest priority first)
void insertPQ(int x) {
    if (n == SIZE) {
        cout << "Queue is Full!\n";
        return;
    }

    int i = n - 1;
    while (i >= 0 && pq[i] > x) {   // shifting bigger elements right
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    n++;

    cout << x << " inserted\n";
}

// Delete highest priority (smallest value)
void deletePQ() {
    if (n == 0) {
        cout << "Queue is Empty!\n";
        return;
    }

    cout << pq[0] << " deleted\n";

    for (int i = 0; i < n - 1; i++)
        pq[i] = pq[i + 1];

    n--;
}

// Display priority queue
void display() {
    if (n == 0) {
        cout << "Queue is Empty!\n";
        return;
    }

    cout << "Priority Queue: ";
    for (int i = 0; i < n; i++)
        cout << pq[i] << " ";
    cout << endl;
}

int main() {
    insertPQ(30);
    insertPQ(10);
    insertPQ(20);

    display();

    deletePQ();
    display();
}
