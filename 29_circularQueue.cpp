#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue is Full!\n";
        return;
    }
    if (front == -1) front = 0;       // first element
    rear = (rear + 1) % SIZE;
    q[rear] = x;
    cout << x << " inserted\n";
}

// Dequeue
void dequeue() {
    if (front == -1) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << q[front] << " deleted\n";

    if (front == rear) {       // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Peek
void peek() {
    if (front == -1)
        cout << "Queue is Empty!\n";
    else
        cout << "Front = " << q[front] << "\n";
}

// Display
void display() {
    if (front == -1) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << "\n";
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    peek();
}