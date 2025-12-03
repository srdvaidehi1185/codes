#include <iostream>
using namespace std;

struct Node {
    int tag;        // 0 = atom, 1 = sublist
    char data;      // used if tag = 0
    Node* down;     // pointer to sublist
    Node* next;     // next element in same list
};

// print GLL
void print(Node* p) {
    cout << "(";
    while (p != NULL) {
        if (p->tag == 0)
            cout << p->data;        // atom
        else
            print(p->down);         // sublist

        if (p->next != NULL) cout << ", ";
        p = p->next;
    }
    cout << ")";
}

int main() {
    // Create a simple GLL:  (a, (b, c), d)

    Node *a = new Node{0, 'a', NULL, NULL};
    Node *b = new Node{0, 'b', NULL, NULL};
    Node *c = new Node{0, 'c', NULL, NULL};
    Node *d = new Node{0, 'd', NULL, NULL};

    Node *sub = new Node{1, ' ', b, NULL};  // sublist starts at b
    b->next = c;

    a->next = sub;
    sub->next = d;

    cout << "GLL = ";
    print(a);
}
