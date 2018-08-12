#ifndef NULL
#define NULL 0
#endif

class Node
{
    public:
        int data;
        Node* next;
};

Node* Merge (Node* head1, Node* head2)
{
    Node* newHead = NULL;
    Node* newTail = NULL;
    Node* tmp = NULL;
    while ((head1 != NULL) && (head2 != NULL)) {
        if (head1->data < head2->data) {
            tmp = head1;
            head1 = head1->next;
        } else {
            tmp = head2;
            head2 = head2->next;
        }
        if (newHead == NULL) {
            newHead = tmp;
            newTail = tmp;
        } else {
            newTail->next = tmp;
            newTail = tmp;
        }
    }

    if (head1 == NULL) {
        tmp = head2;
    }
    if (head2 == NULL) {
        tmp = head1;
    }
    if (newHead == NULL) {
        newHead = tmp;
        newTail = tmp;
    } else {
        newTail->next = tmp;
    }

    return newHead;
}


#ifdef TEST
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    return 0;
}

#endif
