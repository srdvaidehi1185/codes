#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int x) {
    Node* n = new Node;
    n->data = x;

    if (head == NULL) {          // empty list
        head = n;
        n->next = head;
    }
    else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        n->next = head;
        temp->next = n;
        head = n;
    }
}

// Insert at end
void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = n;
    n->next = head;
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) return;

    if (head->next == head) {   // only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    Node* del = head;
    head = head->next;
    temp->next = head;
    delete del;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) return;

    if (head->next == head) {   // only one node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    Node* del = temp->next;
    temp->next = head;
    delete del;
}

// Traverse
void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Search
void search(int key) {
    if (head == NULL) {
        cout << "Not found\n";
        return;
    }

    Node* temp = head;
    do {
        if (temp->data == key) {
            cout << "Found\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Not found\n";
}

int main() {

    insertBegin(10);
    insertEnd(20);
    insertEnd(30);

    display();

    deleteBegin();
    display();

    deleteEnd();
    display();

    search(20);

    return 0;
}