#include <iostream>
using namespace std;

// recursive function
int fact(int n) {
    if (n == 0) return 1;     // base case
    return n * fact(n - 1);   // recursive call
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << "Factorial = " << fact(n);
}
