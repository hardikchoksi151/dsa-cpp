#include <bits/stdc++.h>
using namespace std;

void fib(int n)
{
	fib(n - 1);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " [integer]" << endl;
		return 0;
	}

	int n = stoi(argv[1]);
	fib(n);
}
