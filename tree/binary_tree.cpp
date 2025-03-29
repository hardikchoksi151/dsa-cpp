#include<bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}

TreeNode* buildTree(vector<int>& v) {
	if (!v.size())
		return nullptr;

	TreeNode* root = new TreeNode(v[0]);	
			
	queue<TreeNode*> q;
	q.push(root);

	int i = 1;
	while(i < v.size()) {
		TreeNode* curr = q.front();
		q.pop();

		if (v[i] != -1) {
			curr->left = new TreeNode(v[i]);
			q.push(curr->left);
		}
		i++;

		if (i < v.size() && v[i] != -1) {
			curr->right = new TreeNode(v[i]);
			q.push(curr->right);
		}
		i++;
	}			
}
