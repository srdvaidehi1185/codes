#include <iostream>
using namespace std;

#define SIZE 5
int dq[SIZE];
int front = -1, rear = -1;

// Insert at front
void insertFront(int x) {
    if ((front == 0 && rear == SIZE-1) || (front == rear+1)) {
        cout << "Deque Full!\n";
        return;
    }
    if (front == -1) front = rear = 0;
    else if (front == 0) front = SIZE-1;
    else front--;

    dq[front] = x;
    cout << x << " inserted at front\n";
}

// Insert at rear
void insertRear(int x) {
    if ((front == 0 && rear == SIZE-1) || (front == rear+1)) {
        cout << "Deque Full!\n";
        return;
    }
    if (front == -1) front = rear = 0;
    else if (rear == SIZE-1) rear = 0;
    else rear++;

    dq[rear] = x;
    cout << x << " inserted at rear\n";
}

// Delete from front
void deleteFront() {
    if (front == -1) {
        cout << "Deque Empty!\n";
        return;
    }
    cout << dq[front] << " deleted from front\n";

    if (front == rear) front = rear = -1;
    else if (front == SIZE-1) front = 0;
    else front++;
}

// Delete from rear
void deleteRear() {
    if (front == -1) {
        cout << "Deque Empty!\n";
        return;
    }
    cout << dq[rear] << " deleted from rear\n";

    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = SIZE-1;
    else rear--;
}

// Display
void display() {
    if (front == -1) {
        cout << "Deque Empty!\n";
        return;
    }
    cout << "Deque: ";
    int i = front;
    while (i != rear) {
        cout << dq[i] << " ";
        i = (i + 1) % SIZE;
    }
    cout << dq[rear] << endl;
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}
