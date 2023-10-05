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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        bool carry = false;

        while (p && q) {
            p = p->next;
            q = q->next;
        }

        if (!p) {
            std::swap(l1, l2);
        }

        p = l1;
        q = l2;

        while (q) {
            p->val += q->val + carry;
            carry = p->val >= 10;
            p->val %= 10;
            if (carry && !p->next) {
                p->next = new ListNode(0);
            }
            p = p->next;
            q = q->next;
        }

        while (p && carry) {
            p->val += carry;
            carry = p->val >= 10;
            p->val %= 10;
            if (carry && !p->next) {
                ListNode *add = new ListNode(0);
                p->next = add;
            }
            p = p->next;
        }

        return l1;
    }
};