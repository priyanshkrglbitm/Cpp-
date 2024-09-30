#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->value << " "; // Visit the current node
    preorderTraversal(root->left); // Traverse left subtree recursively
    preorderTraversal(root->right); // Traverse right subtree recursively
}

void InorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    InorderTraversal(root->left); // Traverse left subtree recursively
    cout << root->value << " "; // Visit the current node
    InorderTraversal(root->right); // Traverse right subtree recursively
}

void PostorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    PostorderTraversal(root->left); // Traverse left subtree recursivelycout << root->value << " "; // Visit the current node
    PostorderTraversal(root->right); // Traverse right subtree recursively
    cout << root->value << " "; // Visit the current node
}


int main() {
    
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform preorder traversal
    cout << "Preorder Traversal: ";
    preorderTraversal(root);

    cout <<endl<< "Inorder Traversal: ";
    InorderTraversal(root);

    cout <<endl<< "Postorder Traversal: ";
    PostorderTraversal(root);

    return 0;
}