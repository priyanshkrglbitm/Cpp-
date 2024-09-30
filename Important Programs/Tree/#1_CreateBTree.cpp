#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* createTree() {
        cout << "Enter the root value: ";
        int rootValue;
        cin >> rootValue;

        TreeNode* root = new TreeNode(rootValue);
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            int leftValue, rightValue;
            cout << "Enter the left child value of " << current->val << " (-1 if none): ";
            cin >> leftValue;
            if (leftValue != -1) {
                current->left = new TreeNode(leftValue);
                q.push(current->left);
            }

            cout << "Enter the right child value of " << current->val << " (-1 if none): ";
            cin >> rightValue;
            if (rightValue != -1) {
                current->right = new TreeNode(rightValue);
                q.push(current->right);
            }
        }

        return root;
    }
};

int main() {
    Solution sol;
    TreeNode* root = sol.createTree();

    // Now you have the root of the binary tree created by the user
    // You can perform any operations on this tree as needed

    return 0;
}
