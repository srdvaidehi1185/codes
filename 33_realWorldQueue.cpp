#include <iostream>
using namespace std;

#define SIZE 5
string q[SIZE];
int front = -1, rear = -1;

// Add print job
void enqueue(string job) {
    if (rear == SIZE - 1) {
        cout << "Queue Full! Cannot add job.\n";
        return;
    }
    if (front == -1) front = 0;
    q[++rear] = job;
    cout << job << " added to queue\n";
}

// Process print job
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "No jobs to print!\n";
        return;
    }
    cout << q[front] << " is being printed...\n";
    front++;
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Pending Jobs: ";
    for (int i = front; i <= rear; i++)
        cout << q[i] << "  ";
    cout << "\n";
}

int main() {
    enqueue("File1.pdf");
    enqueue("Image.png");
    enqueue("Report.docx");

    display();

    dequeue(); // prints File1.pdf
    dequeue(); // prints Image.png

    display();

    return 0;
}