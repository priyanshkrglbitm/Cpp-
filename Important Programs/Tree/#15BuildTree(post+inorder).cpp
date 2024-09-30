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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTreeRecursive(inorder, 0, inorder.size() - 1,
                                             postorder, 0, postorder.size() - 1, mpp);
        return root;
    }

private:
    TreeNode* buildTreeRecursive(
        vector<int>& inorder, int inStart, int inEnd,
        vector<int>& postorder, int postStart, int postEnd, map<int,int> &mpp
    ) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[root->val];
        int numLeft = inRoot - inStart;

        root->left = buildTreeRecursive(inorder, inStart, inRoot - 1,
                                        postorder, postStart, postStart + numLeft - 1, mpp);

        root->right = buildTreeRecursive(inorder, inRoot + 1, inEnd,
                                         postorder, postStart + numLeft, postEnd - 1, mpp);

        return root;
    }
};

// Function to print the tree in inorder traversal
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    // Given inorder and postorder traversals
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    // Build the tree
    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print the tree in inorder traversal
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
