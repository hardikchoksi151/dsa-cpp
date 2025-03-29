#include <bits/stdc++.h>
using namespace std;

void print_subsets(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    // op1
    string include = op;
    include.push_back(ip[0]);
    // op2
    string notInclude = op;
    // make ip smaller
    ip.erase(ip.begin());
    // make calls again
    print_subsets(ip, include);
    print_subsets(ip, notInclude);
}

int main()
{
    string ip;
    cin >> ip;

    string op = "";

    print_subsets(ip, op);

    return 0;
}