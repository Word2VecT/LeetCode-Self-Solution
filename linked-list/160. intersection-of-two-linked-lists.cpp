#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p, *q;
        int lenA = 0, lenB = 0;

        p = headA;
        while (p) {
            p = p->next;
            lenA++;
        }
        p = headB;
        while (p) {
            p = p->next;
            lenB++;
        }

        p = headA;
        q = headB;
        if (lenA > lenB) {
            std::swap(p, q);
            std::swap(lenA, lenB);
        }

        for (int i = 0; i < lenB - lenA; i++) {
            q = q->next;
        }

        while (p && q && p != q) {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};

// TODO: 官方题解的方法能少便利几个