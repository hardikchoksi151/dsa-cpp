#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums, int k)
{
    int n = nums.size();

    int l = 0, r = k - 1;
    int count = 0;

    vector<int> res(n - k + 1);

    while (r < n - k + 1)
    {
        if (r > 0 && nums[r - 1] + 1 == nums[r])
            count++;

        if (r - l + 1 > k)
        {
            if (nums[l] + 1 == nums[l + 1])
                count--;
            l++;
        }

        if (r - l + 1 == k)
            res.push_back(count == k ? nums[r] : -1);

        r++;
    }
}

int main()
{
    return 0;
}