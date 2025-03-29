#include <bits/stdc++.h>
#define P pair<int, int> // <cost, dest>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& graph, int n, int source) {
	unordered_map<int, vector<P>> adj;

	for (auto &edge: graph) {
		int u = edge[0], v = edge[1], w = edge[2];
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	priority_queue<P, vector<P>, greater<P>> minHeap;
	minHeap.push({0, source});
	
	vector<int> res(n, INT_MAX);
	res[source] = 0;

	while (!minHeap.empty()) {
		int cost = minHeap.top().first;
		int node = minHeap.top().second;
		minHeap.pop();

		for (auto &nbr: adj[node]) {
			int v = nbr.first;
			int costV = nbr.second;

			int newCost = cost + costV;
			if (newCost < res[v]) {
				minHeap.push({newCost, v});
				res[v] = newCost;
			}
		}
	}

	return res;
}

int main() {
	vector<vector<int>> g = {{0, 2, 6}, {0, 1, 1}, {1, 2, 3}};
	int n = 3;
	int source = 2;
	vector<int> res = dijkstra(g, n, source);
	for (int i = 0; i < n; i++) 
		cout << "min cost to reach node " << i << ", from source " << source << " is : " << res[i] << endl;
	return 0;
}
