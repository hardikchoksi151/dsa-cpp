#include <bits/stdc++.h>
using namespace std;

void toh(int, int, int, int);

int main()
{
    int n;
    cin >> n;
    toh(n, 1, 2, 3);
}

void toh(int n, int A, int B, int C)
{
    // base condition:- think of smallest possible input
    if (n == 0)
    {
        return;
    }

    // hypothesis:- establish hypothesis for a smaller input
    toh(n - 1, A, C, B); // a. move (n - 1) disks from tower A to tower B using tower C

    // Induction
    cout << A << " -> " << C << endl; // manually move remaining 1 disk from tower A to C
    toh(n - 1, B, A, C);              // move those (n - 1) disks from tower B to C
}