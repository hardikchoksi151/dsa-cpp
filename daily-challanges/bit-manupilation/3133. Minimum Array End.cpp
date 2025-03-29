#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll minEnd(int n, int x)
{
    ll res = x;
    for (int i = 1; i < n; ++i)
    {
        res++;
        res |= x;
    }
    return res;
}

int main()
{
    int n, x;
    cin >> n >> x;
    cout << minEnd(n, x);
    return 0;
}