#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

void printPaths(TreeNode* root, vector<int>& path) {
    if (root == nullptr) {
        return;
    }

    path.push_back(root->val);

    // If current node is a leaf node, print the path
    if (root->left == nullptr && root->right == nullptr) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        // Recursively traverse left and right subtrees
        printPaths(root->left, path);
        printPaths(root->right, path);
    }

    // Remove the current node from the path to backtrack
    path.pop_back();
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    root->right->right->right->right = new TreeNode(11);

    vector<int> path;
    printPaths(root, path);

    return 0;
}
