#include <stdio.h>
#include <stack>

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

Node * build_tree(int *& array, int& len)
{
    if (len <= 0) return NULL;
    int v = array[0];
    array++;
    len--;
    if (v == -1) return NULL;

    Node *n = new Node(v);
    n->left = build_tree(array, len);
    n->right = build_tree(array, len);
    return n;
}

#if 0
#define PRINTHASH printf("# ")
#else
#define PRINTHASH
#endif

void preorder_traverse(Node *root)
{
    if (!root) { PRINTHASH; return; }
    printf("%d ", root->value);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void preorder_traverse_stack(Node *root)
{
    std::stack<Node *> s;
    while (root) {
        printf("%d ", root->value);
        if (root->left) {
            if (root->right) {
                s.push(root->right);
            }
            root = root->left;
        } else if (root->right) {
            root = root->right;
        } else if (s.size() > 0) {
            root = s.top();
            s.pop();
        } else {
            break;
        }
    }
}

void inorder_traverse(Node *root)
{
    if (!root) { PRINTHASH; return; }
    inorder_traverse(root->left);
    printf("%d ", root->value);
    inorder_traverse(root->right);
}

void inorder_traverse_stack(Node *root)
{
    std::stack<Node *> s;
    bool go_left = true;
    while (root) {
        bool last = go_left;
        go_left = true;
        if (last && root->left) {
            s.push(root);
            root = root->left;
        } else if (root->right) {
            printf("%d ", root->value);
            root = root->right;
        } else {
            printf("%d ", root->value);
            if (s.size() > 0) {
                root = s.top();
                s.pop();
                go_left = false;
            } else {
                break;
            }
        }
    }
}

void postorder_traverse(Node *root)
{
    if (!root) { PRINTHASH; return; }
    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%d ", root->value);
}

void postorder_traverse_stack(Node *root)
{
    std::stack<Node *> s;
    Node * last_print = NULL;
    while (root) {
        if (last_print && (last_print == root->left || last_print == root->right)) {
            printf("%d ", root->value);
            last_print = root;
            if (s.size() > 0) {
                root = s.top();
                s.pop();
                continue;
            } else {
                break;
            }
        }
        if (root->left) {
            s.push(root);
            if (root->right) {
                s.push(root->right);
            }
            root = root->left;
        } else if (root->right) {
            s.push(root);
            root = root->right;
        } else {
            printf("%d ", root->value);
            last_print = root;
            if (s.size() > 0) {
                root = s.top();
                s.pop();
            } else {
                break;
            }
        }
    }
}

void test1()
{
    int tree1[] = {0, 1, 3, 7, -1, -1, 8, -1, -1, 4, -1, -1, 2, 5, 11, -1, -1, -1, 6, -1, 14, -1, -1};
    int *ptree1 = tree1;
    int len1 = sizeof(tree1) / sizeof(int);
    Node * root1 = build_tree(ptree1, len1);
    preorder_traverse(root1); printf("\n");
    preorder_traverse_stack(root1); printf("\n");
    inorder_traverse(root1); printf("\n");
    inorder_traverse_stack(root1); printf("\n");
    postorder_traverse(root1); printf("\n");
    postorder_traverse_stack(root1); printf("\n");
}

int main()
{
    test1();
    return 0;
}
