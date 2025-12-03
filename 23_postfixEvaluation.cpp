#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp;
    cout << "Enter Postfix Expression: ";
    cin >> exp;

    stack<int> st;

    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');   // convert char to number
        } else {
            int b = st.top(); st.pop();   // second number
            int a = st.top(); st.pop();  // first number

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    cout << "Result = " << st.top();
}
