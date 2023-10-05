#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *s = dummy;

        while (p && q) {
            if (p->val < q->val) {
                s->next = p;
                p = p->next;
            } else {
                s->next = q;
                q = q->next;
            }
            s = s->next;
        }

        if (!p) {
            std::swap(p, q);
        }

        s->next = p;
        p = dummy->next;
        delete dummy;

        return p;
    }
};