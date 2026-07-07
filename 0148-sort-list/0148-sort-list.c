#include <stdlib.h>

// Definition for singly-linked list.
    int val;
    struct ListNode *next;

// Helper function to merge two sorted lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 ? l1 : l2);
    return dummy.next;
}

// Helper function to find the middle of the list
struct ListNode* getMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    // Split list into two halves
    struct ListNode* mid = getMiddle(head);
    struct ListNode* right = mid->next;
    mid->next = NULL;

    // Recursively sort both halves
    struct ListNode* leftSorted = sortList(head);
    struct ListNode* rightSorted = sortList(right);

    // Merge sorted halves
    return merge(leftSorted, rightSorted);
}
