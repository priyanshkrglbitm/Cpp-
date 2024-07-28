#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor for the tree node
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    TreeNode* root; // Root node of the tree

public:

    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return;
        }
        // Queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if (temp->left == nullptr) {
                temp->left = new TreeNode(val);
                return;
            } else {
                q.push(temp->left);
            }
            
            if (temp->right == nullptr) {
                temp->right = new TreeNode(val);
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void levelOrderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
    }

    // Wrapper function to perform in-order traversal from the root
    void displayInorder() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    // Wrapper function to perform level-order traversal from the root
    void displayLevelOrder() {
        cout << "Level Order Traversal: ";
        levelOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    bt.insert(10);
    bt.insert(4);
    bt.insert(7);
    bt.insert(12);
    bt.displayInorder(); 
    bt.displayLevelOrder(); 

    return 0;
}
