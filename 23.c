#include <stdio.h>
#include <stdlib.h>
 struct ListNode {
 int val;
 struct ListNode *next;
 };



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int i;
    int minIndex = 0;
    int nullCount = 0;
    while (nullCount != listsSize) {
        nullCount = 0;
        for (i = 0; i < listsSize; i++) {
            if (lists[i] == NULL) {
                nullCount++;
                continue;
            }
            if (lists[i]->val < lists[minIndex]->val) {
                minIndex = i;
            }
        }
        if (tail == NULL) {
            tail = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            tail->next = NULL;
            head = tail;
        } else {
            tail->next = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    return head;
}

int numbers[] =
{
    10, 20, 30, 40, 50, -1,
    1,2,3,4,5,-1,
    31,55,-1,
    1,2,90,-1,
};

void dumplist(struct ListNode* head)
{
    struct ListNode* n = head;
    while (n) {
        printf("%d, ", n->val);
        n = n->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* lists[100] = {NULL};
    int listsSize = 0;
    int i;
    struct ListNode* tail;
    for (i = 0; i < sizeof(numbers)/sizeof(int); i++) 
    {
        struct ListNode* node;
        int n = numbers[i];
        if (n < 0) {
            listsSize++;
            continue;
        }
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = n;
        node->next = NULL;
        if (lists[listsSize] == NULL) {
            lists[listsSize] = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    for (i = 0; i < listsSize; i++) {
        dumplist(lists[i]);
    }
    dumplist(mergeKLists(lists, listsSize));
    return 0;
}
