#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backtrack(int i, int sum, string s, int num, vector<vector<int>> &t)
    {
        if (i == s.length())
            return sum == num;

        if (sum > num)
            return false;

        if (t[i][sum] != -1)
            return t[i][sum];

        bool possible = false;
        for (int j = i; j < s.length(); j++)
        {
            string currentString = s.substr(i, j - i + 1);
            int addend = stoi(currentString);

            possible = possible || backtrack(j + 1, sum + addend, s, num, t);
            if (possible == true)
                return true;
        }

        return t[i][sum] = possible;
    }

    int punishmentNumber(int n)
    {
        int punishmentNum = 0;
        for (int num = 1; num <= n; num++)
        {
            int squareNum = num * num;
            string s = to_string(squareNum);

            vector<vector<int>> t(s.size(), vector<int>(num + 1, -1));

            if (backtrack(0, 0, s, num, t))
            {
                punishmentNum += squareNum;
            }
        }
        return punishmentNum;
    }
};

int main()
{
}