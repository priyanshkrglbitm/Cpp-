#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr),right(nullptr){}
};

bool getPath(TreeNode* root , vector<int> &res , int node){
    if(root==nullptr){return false;}

    res.push_back(root->val);

    if(root->val == node ){
        return true;
    }
    //required node in either left subtree or right
    if( getPath(root->left , res, node)|| getPath(root->right , res, node) ){
        return true;
    }

    // if above is false means node is neither in right subtree nor in  left subtree.
    res.pop_back();
    return false;
}

int main(){

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

    vector<int> ans ;
    getPath(root , ans , 9);

    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;

 }