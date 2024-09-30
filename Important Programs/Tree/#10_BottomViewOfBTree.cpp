#include<bits/stdc++.h>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val) , left(nullptr) , right(nullptr){}  
};

class Solution{
    public:
    vector<int> topView( TreeNode* root){
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        map<int,int>mpp;
        queue<pair<TreeNode* , int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node= it.first;
            int line=it.second;
          
            mpp[line]=node->val;  // Always update the value associated with the horizontal distance
            
            if(node->left){
                q.push({node->left,line-1});
            }

            if(node->right){
                q.push({node->right,line+1});
            }
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
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
    vector<int>res = sol.topView(root);
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
}

//                  1
//                 / \
//                2   3
//               /\   /\
//              4  5 6  7
//                 /   /\
//                8   9  10
//                        \
//                         11