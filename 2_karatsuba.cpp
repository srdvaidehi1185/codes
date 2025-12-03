#include <iostream>
#include <cmath>
using namespace std;

long long calls = 0, muls = 0, adds = 0;

// adds leading zeros at left to make both strings equal length
string pad(string a, int n) {
    while (a.length() < n) a = "0" + a;
    return a;
}

// converts string integer to long long
long long toInt(string s) {
    long long n = 0;
    for (char c : s) n = n*10 + (c - '0');
    return n;
}

// converts long long back to string
string toStr(long long n) {
    return to_string(n);
}

// Karatsuba multiplication
string karatsuba(string a, string b) {
    calls++;  // count recursive call

    // make lengths equal
    int n = max(a.length(), b.length());
    a = pad(a, n);
    b = pad(b, n);

    // base case: single digit multiply
    if (n == 1) {
        muls++;
        int x = (a[0]-'0') * (b[0]-'0');
        return toStr(x);
    }

    int mid = n/2;

    // split numbers
    string a1 = a.substr(0, n-mid);
    string a2 = a.substr(n-mid);
    string b1 = b.substr(0, n-mid);
    string b2 = b.substr(n-mid);

    // recursive calls
    string p1 = karatsuba(a1, b1);
    string p2 = karatsuba(a2, b2);

    // (a1+a2) and (b1+b2)
    long long aa = toInt(a1) + toInt(a2); adds++;
    long long bb = toInt(b1) + toInt(b2); adds++;

    string p3 = karatsuba(toStr(aa), toStr(bb));

    // compute middle term: p3 - p1 - p2
    long long m = toInt(p3) - toInt(p1) - toInt(p2);
    adds += 2;

    // final result = p1*10^(2*mid) + m*10^(mid) + p2
    string res = toStr(toInt(p1) * (long long)pow(10,2*mid) +
                       m * (long long)pow(10,mid) +
                       toInt(p2));

    return res;
}

int main() {
    string a, b;
    cout << "Enter two large numbers: ";
    cin >> a >> b;

    string ans = karatsuba(a, b);

    cout << "\nResult = " << ans << endl;
    cout << "Recursive Calls = " << calls << endl;
    cout << "Multiplications = " << muls << endl;
    cout << "Additions = " << adds << endl;
}