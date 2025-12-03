#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1) {            // queue full
        cout << "Overflow! Queue is full.\n";
        return;
    }
    if (front == -1) front = 0;        // first element
    queue[++rear] = x;
    cout << x << " inserted.\n";
}

void dequeue() {
    if (front == -1 || front > rear) { // queue empty
        cout << "Underflow! Queue is empty.\n";
        return;
    }
    cout << queue[front] << " deleted.\n";
    front++;
}

void peek() {
    if (front == -1 || front > rear)
        cout << "Queue is empty.\n";
    else
        cout << "Front element = " << queue[front] << "\n";
}

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << "\n";
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
}
