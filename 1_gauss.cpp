#include <iostream>
using namespace std;

int calls = 0, muls = 0, adds = 0;

// Gauss multiplication for 2-digit numbers
int gaussMul(int a, int b) {
    calls++;

    int x = a / 10;     // first digit of a
    int y = a % 10;     // second digit of a
    int u = b / 10;     // first digit of b
    int v = b % 10;     // second digit of b

    int p1 = x * u;     muls++;
    int p2 = y * v;     muls++;
    int p3 = (x + y) * (u + v);  muls++; adds += 2;

    int mid = p3 - p1 - p2;  adds += 2;

    int result = p1 * 100 + mid * 10 + p2;
    muls += 2; adds += 2;    // final multiplications & additions

    return result;
}

int main() {
    int a, b;
    cout << "Enter two 2-digit numbers: ";
    cin >> a >> b;

    int ans = gaussMul(a, b);

    cout << "\nResult = " << ans << endl;
    cout << "Recursive Calls = " << calls << endl;
    cout << "Multiplications = " << muls << endl;
    cout << "Additions = " << adds << endl;
}
