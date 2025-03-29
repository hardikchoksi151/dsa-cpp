#include <bits/stdc++.h>
using namespace std;

int kthSymbolInGrammer(int, int);

int main()
{
    int n, k;
    cin >> n >> k;
    cout << kthSymbolInGrammer(n, k);
    return 0;
}

int kthSymbolInGrammer(int n, int k)
{
    // base condition
    if (n == 1)
        return 0;

    // hypothesis and induction
    int mid = pow(2, n - 2);

    if (k > mid)
        return kthSymbolInGrammer(n - 1, k - mid) == 0 ? 1 : 0;
    else
        return kthSymbolInGrammer(n - 1, k);
}