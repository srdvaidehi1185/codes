/*
Write a program to implement a greedy algorithm to solve a real-world optimization problem, such as minimizing currency notes in a digital wallet (coin change). write the logic using pseudo-code and a flowchart. Analyse the algorithm's time complexity (Best, Average, Worst Case) using Big-O, Θ, and Ω notations.
*/

#include <iostream>
using namespace std;

int main() {
    int amount;
    int notes[] = {100, 50, 20, 10, 5, 1};
    
    cout << "Enter amount: ";
    cin >> amount;

    for (int i = 0; i < 6; i++) {
        int count = amount / notes[i];
        if (count > 0)
            cout << notes[i] << " : " << count << endl;
        amount = amount % notes[i];
    }
}
