#include <bits/stdc++.h>
using namespace std;

void printV(vector<string> &v)
{
	for (string &str : v)
		cout << str << endl;
	cout << endl;
}

void solve(int open, int close, string op, vector<string> &v)
{
	if (open == 0 && close == 0)
	{
		v.push_back(op);
		return;
	}

	if (open > 0)
	{
		solve(open - 1, close, op + "(", v);
	}
	if (close > open)
		solve(open, close - 1, op + ")", v);
}

vector<string> generateParanthesis(int n)
{
	vector<string> res;
	int open = n, close = n;
	string op = "";
	solve(open, close, op, res);
	return res;
}

int main()
{
	int n;
	cin >> n;
	auto res = generateParanthesis(n);
	printV(res);
}
