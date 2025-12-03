#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    n->prev = NULL;

    if (head != NULL)
        head->prev = n;

    head = n;
}

// Insert at end
void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// Insert at position (1-based)
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

    if (temp == NULL) return;

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}

// Delete at beginning
void deleteBegin() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

// Delete at end
void deleteEnd() {
    if (head == NULL) return;

    Node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        delete temp;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

// Delete at position
void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;
}

// Display forward
void displayForward() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Display reverse
void displayReverse() {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
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

int main() {
    insertBegin(30);
    insertBegin(20);
    insertEnd(40);
    insertPos(25, 2);

    cout << "Forward: ";
    displayForward();

    cout << "Reverse: ";
    displayReverse();

    search(25);

    deletePos(2);
    displayForward();
}
