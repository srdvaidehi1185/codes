#include <iostream>
#include <stack>
using namespace std;

struct Move {
    int n;      // number of disks
    char from;  // source rod
    char to;    // destination rod
    char aux;   // helper rod
};

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    stack<Move> st;
    st.push({n, 'A', 'C', 'B'});   // initial problem

    while (!st.empty()) {
        Move m = st.top();
        st.pop();

        // if only 1 disk → direct move
        if (m.n == 1) {
            cout << "Move disk from " << m.from << " to " << m.to << endl;
        } else {
            // push in reverse order (because stack = LIFO)
            st.push({m.n - 1, m.aux, m.to, m.from});  // step 3
            st.push({1, m.from, m.to, m.aux});        // step 2
            st.push({m.n - 1, m.from, m.aux, m.to});  // step 1
        }
    }

    return 0;
}