#include <iostream>
using namespace std;

struct Node {
    int coeff, exp;
    Node* next;
};

Node* insert(Node* head, int c, int e) {
    Node* t = new Node;
    t->coeff = c;
    t->exp = e;
    t->next = NULL;

    if (head == NULL) return t;

    Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = t;
    return head;
}

// Add two polynomials
Node* add(Node* A, Node* B) {
    Node* C = NULL;

    while (A != NULL && B != NULL) {
        if (A->exp == B->exp) {
            C = insert(C, A->coeff + B->coeff, A->exp);
            A = A->next;
            B = B->next;
        }
        else if (A->exp > B->exp) {
            C = insert(C, A->coeff, A->exp);
            A = A->next;
        }
        else {
            C = insert(C, B->coeff, B->exp);
            B = B->next;
        }
    }

    while (A != NULL) {
        C = insert(C, A->coeff, A->exp);
        A = A->next;
    }
    while (B != NULL) {
        C = insert(C, B->coeff, B->exp);
        B = B->next;
    }

    return C;
}

void print(Node* p) {
    while (p != NULL) {
        cout << p->coeff << "x^" << p->exp;
        if (p->next != NULL) cout << " + ";
        p = p->next;
    }
}

int main() {
    Node *A = NULL, *B = NULL;

    // Example polynomial 1: 3x^3 + 2x^1
    A = insert(A, 3, 3);
    A = insert(A, 2, 1);

    // Example polynomial 2: 4x^3 + 1x^1
    B = insert(B, 4, 3);
    B = insert(B, 1, 1);

    Node* C = add(A, B);

    cout << "Result: ";
    print(C);
}
