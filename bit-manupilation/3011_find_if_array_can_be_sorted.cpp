#include <bits/stdc++.h>
using namespace std;

bool canSortArray(vector<int> &);
bool canSortArray1(vector<int> &);

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << canSortArray1(v);
    return 0;
}

bool canSortArray(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        bool f = false;
        for (int j = 0; j < n - i - 1; ++j)
            if (nums[j] > nums[j + 1])
                if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
                {
                    swap(nums[j], nums[j + 1]);
                    f = true;
                }
                else
                    return false;

        if (!f)
            break;
    }

    return true;
}

bool canSortArray1(vector<int> &nums)
{
    int maxOfPrevRegion = INT_MIN;

    int minOfCurrRegion = nums[0];
    int maxOfCurrRegion = nums[0];
    int numOfBitsCurrRegion = __builtin_popcount(nums[0]);

    for (int i = 1; i < nums.size(); ++i)
    {
        if (__builtin_popcount(nums[i]) == numOfBitsCurrRegion)
        {
            minOfCurrRegion = min(minOfCurrRegion, nums[i]);
            maxOfCurrRegion = max(maxOfCurrRegion, nums[i]);
        }
        else
        {
            if (minOfCurrRegion < maxOfPrevRegion)
                return false;

            maxOfPrevRegion = maxOfCurrRegion;

            minOfCurrRegion = nums[i];
            maxOfCurrRegion = nums[i];
            numOfBitsCurrRegion = __builtin_popcount(nums[i]);
        }
    }

    if (maxOfPrevRegion > minOfCurrRegion)
        return false;

    return true;
}