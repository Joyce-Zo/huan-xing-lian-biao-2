#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

 struct ListNode 
{
      int val;
      struct ListNode *next;
  };
 
 // 环形链表
hasCycle(struct ListNode* head) 
{
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next) // fast不会到尾，即是一个环
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)  // 追上
            return fast;
    }
    return -1;   // 没追上
}

// 环形链表进阶
struct ListNode* getIntersectionNode2(struct ListNode* headA, struct ListNode* headB) {
    int la = 0, lb = 0;
    struct ListNode* LA = headA;
    struct ListNode* LB = headB;

    while (LA != 0)
    {
        LA = LA->next;
        la++;
    }
    while (LB != 0)
    {
        LB = LB->next;
        lb++;
    }
    if (LA != LB)
    {
        return NULL;
    }
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if (la < lb)
    {
        longlist = headB;
        shortlist = headA;
    }
    int gap = abs(la - lb);
    while (gap--)
    {
        longlist = longlist->next;
    }

    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * fast, * newhead, * meetNode;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            newhead = slow->next;
            slow->next = NULL;
            meetNode = getIntersectionNode(newhead, head);
            return meetNode;
        }
    }
    return NULL;
}

