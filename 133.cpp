
#include<map>
#include<stack>
#include<vector>
#include<set>
#include<map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

#if 1
#define DEBUG
#else
#define DEBUG printf
#endif

class Solution {
    struct PP
    {
        UndirectedGraphNode* oldnode;
        UndirectedGraphNode* newnode;
        PP(UndirectedGraphNode* o, UndirectedGraphNode* n) {
            oldnode = o;
            newnode = n;
        }
    };
    public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        map<int, UndirectedGraphNode*> copied;
        stack<PP> todo;

        UndirectedGraphNode* newroot = new UndirectedGraphNode(node->label);
        todo.push(PP(node, newroot));
        copied[newroot->label] = newroot;

        while (todo.size() > 0) {
            const PP p = todo.top();
            todo.pop();
            int size = p.oldnode->neighbors.size();
            for (int i = 0; i < size; i++) {
                UndirectedGraphNode* oldcopy = p.oldnode->neighbors[i];
                int label = oldcopy->label;
                UndirectedGraphNode* newcopy = copied[label];
                if (!newcopy) {
                    newcopy = new UndirectedGraphNode(label);
                    copied[label] = newcopy;
                    todo.push(PP(oldcopy, newcopy));
                }
                p.newnode->neighbors.push_back(newcopy);
            }

        }
        return newroot;
    }
};


void printGraph(UndirectedGraphNode* root)
{
    printf("%s\n", __FUNCTION__);
    if (!root) return;
    set<int> done;
    stack<UndirectedGraphNode*> todo;
    todo.push(root);
    while (!todo.empty()) {
        UndirectedGraphNode* p = todo.top();
        todo.pop();
        printf("#%d ", p->label);
        for (int i = 0; i < p->neighbors.size(); i++) {
            UndirectedGraphNode* c = p->neighbors[i];
            printf("%d ", c->label);
            if (done.count(c->label) == 0) {
                done.insert(c->label);
                todo.push(c);
            }
        }
        printf("\n");
    }
}

#define NEXTEND 0
#define NEXTVAL 1
#define NEXTGRP 2
struct GETTER
{
    int val;
    char* input;
    int next()
    {
        char* p = input;
        while (*p) {
            if (*p == '#') {
                val = getval(input, p);
                input = p+1;
                return NEXTGRP;
            } else if (*p == ',') {
                val = getval(input, p);
                input = p+1;
                return NEXTVAL;
            }
            p++;
        }
        val = getval(input, p);
        return NEXTEND;
    }
    int getval(char* s, char* e)
    {
        int v = 0;
        int negitive = 0;
        while (s < e) {
            if (*s == '-') {
                negitive = 1;
            } else {
                v = v*10 + (*s) - '0';
            }
            s++;
        }
        return negitive ? -v : v;
    }
};

UndirectedGraphNode* buildGraph(char * input)
{
    DEBUG("%s\n", __FUNCTION__);
    if (!input) return NULL;

    UndirectedGraphNode* root = NULL;
    UndirectedGraphNode* p = NULL;
    map<int, UndirectedGraphNode*> done;
    GETTER g;
    g.input = input;
    while (1) {
        int ret = g.next();
        int val = g.val;
        UndirectedGraphNode* n = done[val];
        if (n == NULL) {
            n = new UndirectedGraphNode(val);
            done[val] = n;
        }
        DEBUG("new node %d\n", val);
        if (!root) root = n;
        if (p) {
            DEBUG("Add, p=%d, c=%d\n", p->label, n->label);
            p->neighbors.push_back(n);
        } else {
            DEBUG("Add, p=%d\n", n->label);
            p = n;
        }
        if (ret == NEXTGRP) {
            p = NULL;
            DEBUG("group done\n");
        }
        if (ret == NEXTEND) {
            DEBUG("total done\n");
            break;
        }
    }
    return root;
}

int main(int argc, char** argv)
{
    UndirectedGraphNode* root = buildGraph(argv[1]);
    printGraph(root);
    Solution s;
    UndirectedGraphNode* clone = s.cloneGraph(root);
    printGraph(clone);
    return 0;
}
