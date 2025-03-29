#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int backtrack(int i, int currCost, vector<int>& days, unordered_map<int, int>& costs) {
        if (i == days.size()) return 0;

        // try each possibilites
        int res = INT_MAX;
        for (auto& p: costs) {
            for (int j = i; j < days.size(); ++j)
                if (days[j] > days[i] + p.first) break;
            res = min(res, backtrack(j, currCost + p.second, days, costs));
        }
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) { 
        unordered_map<int, int> cost;
        cost[1] = costs[0];
        cost[7] = costs[1];
        cost[30] = costs[2];

        return backtrack(0, 0, days, cost);
    }
};


int main() {
	vector<int> days={1,4,6,7,8,20};
	vector<int> costs{2,7,15};

	Solution obj;

	cout << obj.mincostTickets(days, costs);

	return 0;
}
