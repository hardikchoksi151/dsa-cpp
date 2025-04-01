#include <bits/stdc++.h>
using namespace std;

int bitArrToInt(vector<int> &bits)
{
    int res = 0;

    for (int i = 0; i < 32; ++i)
        if (bits[i] > 0)
            res += (1 << i);

    return res;
}

void updateBits(vector<int> &bits, int n, int diff)
{
    for (int i = 0; i < 32; ++i)
        if ((n & (1 << i)) > 0)
            bits[i] += diff;
}

int minimumSubarrayLength(vector<int> &nums, int k)
{
    int l = 0;
    vector<int> bits(32, 0);
    int minLength = INT_MAX;

    for (int r = 0; r < nums.size(); ++r)
    {
        updateBits(bits, nums[r], 1);
        int currOr = bitArrToInt(bits);

        while (l <= r && currOr >= k)
        {
            minLength = min(minLength, (r - l + 1));
            updateBits(bits, nums[l], -1);
            currOr = bitArrToInt(bits);
            l++;
        }
    }

    return minLength == INT_MAX ? -1 : minLength;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << minimumSubarrayLength(nums, k);

    return 0;
}
