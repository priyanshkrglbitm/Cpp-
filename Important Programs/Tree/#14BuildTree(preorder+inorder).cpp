#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTreeRecursive(preorder, 0, preorder.size() - 1,
                                             inorder, 0, inorder.size() - 1, mpp);
        return root;
    }

private:
    TreeNode* buildTreeRecursive(
        vector<int>& preorder, int preStart, int preEnd,
        vector<int>& inorder, int inStart, int inEnd, map<int,int> &mpp
    ) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root->val];
        int numLeft = inRoot - inStart;

        root->left = buildTreeRecursive(preorder, preStart + 1, preStart + numLeft,
                                        inorder, inStart, inRoot - 1, mpp);

        root->right = buildTreeRecursive(preorder, preStart + numLeft + 1, preEnd,
                                         inorder, inRoot + 1, inEnd, mpp);

        return root;
    }
};

// Function to print the tree in preorder traversal
void printPreorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution sol;

    // Given preorder and inorder traversals
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> preorder = {10, 20, 40, 50, 30, 60};

    // Build the tree
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Print the tree in preorder traversal
    cout << "Preorder traversal of the constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
