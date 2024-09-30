#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    vector<int> BoundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }

        if (!isLeaf(root)) {
            res.push_back(root->val);
        }
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }

private:

    //Check whether the node is leaf or not
    bool isLeaf(TreeNode* root) {
    // If the node is nullptr, it cannot be a leaf
    if (root == nullptr) {
        return false;
    }
    // If both left and right children are nullptr, then it's a leaf
    return (root->left == nullptr && root->right == nullptr);
}


    // Function to add left boundary
    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->val);
            }

            if (curr->left) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        } 
    }

    // Function to add leaves
    void addLeaves(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if (root->left) {
            addLeaves(root->left, res);
        }
        if (root->right) {
            addLeaves(root->right, res);
        }
    }

    // Function To add right boundary
    void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->val);
            }

            if (curr->right) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    Solution sol;
    vector<int> boundary = sol.BoundaryOfBinaryTree(root);
    cout << "Boundary of the binary tree: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
