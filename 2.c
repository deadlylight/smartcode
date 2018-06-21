#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int addition = 0;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int bothEmpty = ((l1 == NULL) && (l2 == NULL));
    while (l1 || l2) {
        int v1 = 0;
        int v2 = 0;
        int ret;
        struct ListNode* n;
        if (l1) {
            v1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            v2 = l2->val;
            l2 = l2->next;
        }
        ret = v1 + v2 + addition;
        addition = ret / 10;
        ret = ret % 10;
        n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->val = ret;
        n->next = NULL;

        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    if ((bothEmpty) || (addition > 0)) {
        struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->val = addition;
        n->next = NULL;
        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    return head;
}

void print(struct ListNode* head)
{
    while (head) {
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode a5 = {9, NULL};
    struct ListNode a4 = {8, &a5};
    struct ListNode a3 = {7, &a4};
    struct ListNode a2 = {1, &a3};
    struct ListNode a1 = {5, &a2};

    struct ListNode b5 = {8, NULL};
    struct ListNode b4 = {8, &b5};
    struct ListNode b3 = {8, &b4};
    struct ListNode b2 = {8, &b3};
    struct ListNode b1 = {8, &b2};

    struct ListNode* ret;
    struct ListNode* a = &a1;
    struct ListNode* b = &b3;

    ret = addTwoNumbers(&a1, &b3);
    print(a);
    print(b);
    print(ret);

    print(addTwoNumbers(NULL, NULL));
    print(addTwoNumbers(&a5, &b5));

    return 0;
}
