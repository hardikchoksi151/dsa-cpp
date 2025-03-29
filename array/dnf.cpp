#include<bits/stdc++.h>
using namespace std;

void printv(vector<int> v) {
	cout << "[";
	for (int &i: v) cout << i << ", ";
	cout << "]\n";
}


int main() {
	vector<int> arr = {0, 1, 2, 0, 1, 2, 0, 1, 2};
	int n = arr.size();
 	int l, m, h = n - 1;
	l = m = 0;


	printv(arr);

	while (m <= h) {
		if (arr[m] == 0) 
			swap(arr[m++], arr[l++]);
		else if (arr[m] == 2)
			swap(arr[m++], arr[h--]);
		else 
			m++;
	}


	printv(arr);

	return 0;
}

