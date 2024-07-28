

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode():data(0),left(nullptr),right(nullptr){}
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


class BinaryTree {
private:
    TreeNode* root; 

    TreeNode* insert(TreeNode* node, int val);
    void inorderTraversal(TreeNode* node) ;
    bool search(TreeNode* node, int val) ;

public:

    BinaryTree():root(nullptr){}
    
    // Wrapper Function
    void insert(int val);
    void displayInorder();
    bool search(int val);
};

#endif 
