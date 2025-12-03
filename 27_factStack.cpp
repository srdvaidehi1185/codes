#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    stack<int> st;        // our explicit stack

    // push numbers 1 to n onto stack
    for (int i = 1; i <= n; i++) {
        st.push(i);
    }

    int fact = 1;

    // pop and multiply
    while (!st.empty()) {
        fact *= st.top(); // multiply top value
        st.pop();         // remove top
    }

    cout << "Factorial = " << fact;
}
