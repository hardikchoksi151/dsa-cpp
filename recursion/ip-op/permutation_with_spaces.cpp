#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op)
{
    if (!ip.length())
    {
        cout << op << endl;
        return;
    }

    string includeWithSpace = "_" + ip[0];
    string includeWithoutSpace = "" + ip[0];

    // make ip smaller
    ip.erase(ip.begin());
    solve(ip, includeWithoutSpace);
    solve(ip, includeWithSpace);
}

int main()
{
    string ip;
    cin >> ip;

    solve(ip, "");

    return 0;
}