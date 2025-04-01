#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();
    // remove prefix, keep longest possible postfix
    int r = n - 1;

    while (r > 0 && arr[r - 1] >= arr[r])
    {
        r--;
    }

    int res = r;

    // remove postfix, keep longest possible prefix
    int l = 0;
    while (l < n && arr[l] <= arr[l + 1])
    {
        l++;
    }

    res = min(res, n - 1 - l);

    // remove middle
    l = 0, r = n - 1;

    while (l < r)
    {
        // shrink valid window
        while (r < n && l + 1 < r && arr[r - 1] <= arr[r - 1] && arr[l] < arr[r])
        {
            r--;
        }
        // expand invalid window
        while (r < n && arr[l] > arr[r])
        {
            r++;
        }

        res = min(res, r - l - 1);

        if (arr[l] > arr[l + 1])
            break;

        l++;
    }

    return res;
}

int main()
{
    return 0;
}