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
    n->next = head;
    head = n;
}

// Insert at end
void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
}

// Insert at position (1-based index)
void insertPos(int x, int pos) {
    if (pos == 1) {
        insertBegin(x);
        return;
    }

    Node* n = new Node;
    n->data = x;

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position not valid!\n";
        return;
    }

    n->next = temp->next;
    temp->next = n;
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteEnd() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Delete from position
void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Position not valid!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Search
void search(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found\n";
}

// Display list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main
int main() {
    insertBegin(10);
    insertEnd(20);
    insertEnd(30);
    insertPos(15, 2);

    cout << "List: ";
    display();

    deleteBegin();
    deleteEnd();
    deletePos(2);

    cout << "After deletions: ";
    display();

    search(20);

    return 0;
}
