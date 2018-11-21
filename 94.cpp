  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
  };
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;

        bool goleft = true;
        stack<TreeNode*> s;
        s.push(root);

        while (s.size() > 0) {
            TreeNode* node = s.top();
            if (goleft && node->left) {
                s.push(node->left);
                goleft = true;
            } else {
                ret.push_back(node->val);
                s.pop();
                if (node->right) {
                    s.push(node->right);
                    goleft = true;
                } else {
                    goleft = false;
                }
            }
        }
        return ret;
    }
};


