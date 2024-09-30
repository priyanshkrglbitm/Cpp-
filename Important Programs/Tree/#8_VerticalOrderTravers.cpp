#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): val(val) , left(nullptr),right(nullptr){} 
};


class Solution{
public:
    vector<vector<int>> VerticalOrderTraversal(TreeNode* root){
        // So, nodes is a data structure that can store a collection of values organized by two levels of keys.
        // The first level of keys represents the vertical distance of the nodes from the root, 
        // and the second level of keys represents the level of the nodes in the tree. 
        // Finally, the multiset at each position stores the values of the nodes that share the same vertical distance and level.
        map<int, map<int, multiset<int>>> nodes; 
        
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); //initial vertical and level
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;

            // x -> vertical, y->level
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(temp->val); //inserting to multiset

            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p: nodes) {
            vector<int> col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
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
    vector<vector<int>> res = sol.VerticalOrderTraversal(root);

     for (const auto& col : res) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}