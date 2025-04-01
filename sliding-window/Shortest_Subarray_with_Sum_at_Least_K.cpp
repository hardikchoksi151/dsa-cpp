#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k)
{
    int res = INT_MAX;

    int sum = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int r = 0; r < nums.size(); ++r)
    {
        sum += nums[r];

        if (sum >= k)
            res = min(res, r + 1);

        while (!pq.empty() && sum - pq.top().first >= k)
        {
            auto top = pq.top();
            pq.pop();
            res = min(res, r - top.second);
        }

        pq.push({sum, r});
    }

    return res == INT_MAX ? -1 : res;
}

int main()
{
}