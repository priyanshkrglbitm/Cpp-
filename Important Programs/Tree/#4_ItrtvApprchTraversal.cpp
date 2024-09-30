#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val) , left(nullptr) ,right(nullptr){}
};

//InorderIterative
vector < int > InOrderIterative(TreeNode * root) {
  vector < int > inOrder;
  stack < TreeNode * > s;
  TreeNode* node=root;
  while (true) {
    if (node != NULL) {
      s.push(node);
      node = node -> left;
    } 
    else {
      if (s.empty()) break;

      node = s.top();
      s.pop();
      inOrder.push_back(node -> val);
      node = node -> right;
    }
  }
  return inOrder;
}

//PreOrderIterative
vector < int > preOrderIterative(TreeNode * curr) {
  vector < int > preOrder;
  if (curr == NULL)
    return preOrder;

  stack < TreeNode * > s;
  s.push(curr);

  while (!s.empty()) {
    TreeNode * topNode = s.top();
    preOrder.push_back(topNode -> val);
    s.pop();
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;

}

//PostOrderITerative
vector<int> PostOrderIterative(TreeNode* root) {
    vector<int> result;
    if (root == nullptr)
        return result;

    stack<TreeNode*> s;
    TreeNode* prev = nullptr;
    do {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
        while (root == nullptr && !s.empty()) {
            root = s.top();
            if (root->right == nullptr || root->right == prev) {
                result.push_back(root->val);
                s.pop();
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
    } while (!s.empty());
    return result;
}

//Driver Code
int main()
{

  TreeNode * root = new TreeNode(1);
  root -> left = new TreeNode(2);
  root -> right = new TreeNode(3);
  root -> left -> left = new TreeNode(4);
  root -> left -> right = new TreeNode(5);
  root -> left -> right -> left = new TreeNode(8);
  root -> right -> left = new TreeNode(6);
  root -> right -> right = new TreeNode(7);
  root -> right -> right -> left = new TreeNode(9);
  root -> right -> right -> right = new TreeNode(10);

  vector < int > ans1;
 
  ans1 = preOrderIterative(root);

cout << "The preOrder Traversal is : ";
for (int i = 0; i < ans1.size(); i++) {
    cout << ans1[i] << " ";
  }

cout<<endl;
ans1 = InOrderIterative(root);
cout << "The InOrder Traversal is : ";
  for (int i = 0; i < ans1.size(); i++) {
    cout << ans1[i] << " ";
  }
cout<<endl;

ans1=PostOrderIterative(root);
cout << "The preOrder Traversal is : ";
  for (int i = 0; i < ans1.size(); i++) {
    cout << ans1[i] << " ";
  }
cout<<endl;  
  return 0;
}