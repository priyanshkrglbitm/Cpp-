#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr){}  
};

class Solution{
    public:
    vector<int> sideView(TreeNode* root){
        vector<int>res;
        recursion(root,0,res);
        return res;
    }

private:
    void recursion(TreeNode* root, int level , vector<int> &res){
        if(root==nullptr)return;
        if(res.size()==level){
            res.push_back(root->val);
        }
        recursion(root->left, level+1,res);
        recursion(root->right, level+1,res);
    }

};


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

    Solution sol;
    vector<int>res = sol.sideView(root);
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
    }