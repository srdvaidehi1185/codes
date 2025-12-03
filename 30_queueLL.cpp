#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enqueue (insert at end)
void enqueue(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;

    if (front == NULL) {        // queue empty
        front = rear = n;
    } 
    else {
        rear->next = n;
        rear = n;
    }
    cout << x << " inserted\n";
}

// Dequeue (delete from front)
void dequeue() {
    if (front == NULL) {
        cout << "Queue is Empty!\n";
        return;
    }

    Node* temp = front;
    cout << front->data << " deleted\n";
    front = front->next;

    if (front == NULL)          // queue became empty
        rear = NULL;

    delete temp;
}

// Display queue
void display() {
    if (front == NULL) {
        cout << "Queue is Empty!\n";
        return;
    }

    Node* temp = front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();
}
