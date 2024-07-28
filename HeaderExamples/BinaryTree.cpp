
#include "HeaderBinaryTree.h"

BinaryTree::BinaryTree() : root(nullptr) {}

TreeNode* BinaryTree :: insert(TreeNode* node, int val) {
    if (node == nullptr) {
        return new TreeNode(val);
    }

    if (val < node->data) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }

    return node;
}

// Public insert function
void BinaryTree :: insert(int val) {
    root = insert(root, val);
}

// Private utility function for inorder traversal
void BinaryTree :: inorderTraversal(TreeNode* node){
    if (node == nullptr) return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Public function to display inorder traversal
void BinaryTree :: displayInorder(){
    inorderTraversal(root);
    cout << endl;
}

// Private utility function for searching
bool BinaryTree :: search(TreeNode* node, int val){
    if (node == nullptr) return false;

    if (node->data == val) return true;

    if (val < node->data) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

// Public search function
bool BinaryTree :: search(int val) {
    return search(root, val);
}



int main() {
    BinaryTree bt;

    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(3);
    bt.insert(7);

    // Display the tree using inorder traversal
    cout << "Inorder Traversal: ";
    bt.displayInorder(); // Output: 3 5 7 10 15

    // Search for a node
    int searchValue = 7;
    if (bt.search(searchValue)) {
        cout << "Node " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Node " << searchValue << " not found in the tree." << endl;
    }

    searchValue = 20;
    if (bt.search(searchValue)) {
        cout << "Node " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Node " << searchValue << " not found in the tree." << endl;
    }

    return 0;
}
