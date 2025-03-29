#include <bits/stdc++.h>
using namespace std;

vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
{
    int n = nums.size();
    vector<int> res(n);

    int nXor = 0;
    int mask = (1 << maximumBit) - 1;

    for (int &n : nums)
        nXor ^= n;

    for (int i = n - 1; i > -1; nXor ^= nums[i--])
        res[n - i - 1] = (nXor ^ mask);

    return res;
}

int main()
{
    int n, maximumBit;
    cin >> n;
    cin >> maximumBit;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> res = getMaximumXor(nums, maximumBit);

    for (int &n : res)
        cout << n << " ";

    return 0;
}