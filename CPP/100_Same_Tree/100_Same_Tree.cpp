//https://leetcode.com/problems/same-tree

#define NULL_NODE 10001

#include <iostream>
#include<vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		this->val = 0;
		this->left = nullptr;
		this->right = nullptr;
	}

	TreeNode(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	TreeNode(int val, TreeNode* left, TreeNode* right) {
		this->val = val;
		this->left = left;
		this->right = right;
	}
};

void add_nodes(TreeNode* curr_root, int root_index, std::vector<int> vals) {
	int left_index = 1 + (root_index * 2);
	int right_index = 2 + (root_index * 2);

	if (vals.size() > left_index) {
		if (vals[left_index] != NULL_NODE)
		{
			curr_root->left = new TreeNode(vals[left_index]);
			add_nodes(curr_root->left, left_index, vals);
		}
	}

	if (vals.size() > right_index) {
		if (vals[right_index] != NULL_NODE) {
			curr_root->right = new TreeNode(vals[right_index]);
			add_nodes(curr_root->right, right_index, vals);
		}
	}
}

TreeNode* create_tree(std::vector<int> vals) {
	if (vals.size() > 0) {
		TreeNode* tree = new TreeNode(vals[0]);
		add_nodes(tree, 0, vals);
		return tree;
	}
	return nullptr;
}

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if ((p == nullptr) && (q == nullptr)) {
			return true;
		}
		if ((p == nullptr) || (q == nullptr)) {
			return false;
		}

		if (p->val != q->val) {
			return false;
		}

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

int main() {

	Solution s = Solution();

	TreeNode* p = create_tree(std::vector<int>{});
	TreeNode* q = create_tree(std::vector<int>{});
	std::cout << "Output: " << s.isSameTree(p, q) << "\tExpected: 1" << std::endl;

	p = create_tree(std::vector<int>{1, 2, 3});
	q = create_tree(std::vector<int>{});
	std::cout << "Output: " << s.isSameTree(p, q) << "\tExpected: 0" << std::endl;

	p = create_tree(std::vector<int>{1, 2, 3});
	q = create_tree(std::vector<int>{1, 2, 3});
	std::cout << "Output: " << s.isSameTree(p, q) << "\tExpected: 1" << std::endl;

	p = create_tree(std::vector<int>{1, 2});
	q = create_tree(std::vector<int>{1, NULL_NODE, 2});
	std::cout << "Output: " << s.isSameTree(p, q) << "\tExpected: 0" << std::endl;

	p = create_tree(std::vector<int>{1, 2, 1});
	q = create_tree(std::vector<int>{1, 1, 2});
	std::cout << "Output: " << s.isSameTree(p, q) << "\tExpected: 0" << std::endl;

	p = create_tree(std::vector<int>{1, 2, 3, NULL_NODE, 4});
	q = create_tree(std::vector<int>{1, 2, 3, NULL_NODE, 4});
	std::cout << "Output: " << s.isSameTree(p, q) << "\tExpected: 1" << std::endl;

	return 0;
}