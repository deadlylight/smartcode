 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
#define bool int
#define true 1
#define false 0

void mirror(struct TreeNode* root) {
    if (!root) return;
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

bool issame(struct TreeNode* a, struct TreeNode* b)
{
    if (!a && !b) return true;
    if (a && b) {
        if (a->val != b->val) return false;
        return issame(a->left, b->left) && issame(a->right, b->right);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    bool ret;
    if (!root) return true;
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    mirror(left);
    ret = issame(left, right);
//    mirror(left);
    return ret;
}
