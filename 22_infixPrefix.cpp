#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// function to check precedence of operators
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

// convert infix to prefix
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    // swap ( with )
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<string> st;
    stack<char> op;

    for (int i = 0; i < s.length(); i++) {

        // if digit → read full number
        if (isdigit(s[i])) {
            string num = "";
            while (i < s.length() && isdigit(s[i])) {
                num += s[i];
                i++;
            }
            i--;
            st.push(num);
        }

        else if (s[i] == '(') op.push(s[i]);

        else if (s[i] == ')') {
            while (!op.empty() && op.top() != '(') {
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                char o = op.top(); op.pop();
                st.push(string(1, o) + " " + b + " " + a);
            }
            op.pop();  // pop '('
        }

        else { // operator
            while (!op.empty() && prec(op.top()) >= prec(s[i])) {
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                char o = op.top(); op.pop();
                st.push(string(1, o) + " " + b + " " + a);
            }
            op.push(s[i]);
        }
    }

    while (!op.empty()) {
        string a = st.top(); st.pop();
        string b = st.top(); st.pop();
        char o = op.top(); op.pop();
        st.push(string(1, o) + " " + b + " " + a);
    }

    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    cout << "Prefix: " << infixToPrefix(infix);
}