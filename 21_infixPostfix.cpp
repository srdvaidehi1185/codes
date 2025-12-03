#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to define operator precedence
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    string infix, postfix = "";
    cout << "Enter infix expression: ";
    getline(cin, infix);

    stack<char> st;

    for (int i = 0; i < infix.length(); i++) {

        // Skip spaces
        if (infix[i] == ' ') continue;

        // If it's a digit → read whole number
        if (isdigit(infix[i])) {
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;  
        }

        // Opening bracket
        else if (infix[i] == '(') {
            st.push(infix[i]);
        }

        // Closing bracket
        else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            if (!st.empty()) st.pop();  // remove '('
            else {
                cout << "Error: Mismatched parentheses!\n";
                return 0;
            }
        }

        // Operator
        else {
            while (!st.empty() && prec(st.top()) >= prec(infix[i])) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        if (st.top() == '(') {
            cout << "Error: Mismatched parentheses!\n";
            return 0;
        }
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }

    cout << "Postfix: " << postfix << endl;
    return 0;
}
