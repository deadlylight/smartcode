

struct Node
{
    Node* left;
    Node* right;
    int value;
    int factor;

    Node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
        factor = 0;
};

struct AVL
{
    Node* root;

    enum {
        NONE,
        LEFT,
        RIGHT,
    };

    AVL()
    {
        root = NULL;
    }

    Node* search(int v)
    {
        Node* n = root;
        while (n) {
            if (v < n->value) n = n->left;
            else if (v > n->value) n = n->right;
            else return n;
        }
        return NULL;
    }

    bool insert(int v)
    {
        if (!root) {
            Node* n = new Node(v);
            if (!n) return false;
            root = n;
            return true;
        }

        Node* arr[64] = {NULL};
        int count = 0;
        Node* tmp = root;

        while (tmp) {
            arr[count] = tmp;
            count++;
            if (v < tmp->value) {
                tmp = tmp->left;
            } else if (v > tmp->value) {
                tmp = tmp->right;
            } else {
                return false;
            }
        }

        int direction1 = NONE;
        int direction2 = NONE;
        Node* n = new Node(v);
        if (!n) return false;
        Node* last = arr[count-1];
        if (v < last->value) {
            last->left = n;
            last->factor--;
            direction1 = LEFT;
        } else {
            last->right = n;
            last->factor++;
            direction1 = RIGHT;
        }

        if (count <= 1) return true;
        int i = count - 2;
        Node* pre = NULL;
        while (i >= 0) {
            pre = arr[i];
            if (pre->left == last) pre->factor--;
            else pre->factor++;
            if (pre->factor < -1) {
                direction2 = LEFT;
                break;
            } else if (pre->factor > 1) {
                direction2 = RIGHT;
                break;
            }
        }

        if (direction2 == NONE) {
            return true;
        }



    }
};
