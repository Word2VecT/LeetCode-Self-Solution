struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;
        ListNode *q, *s;

        if (p && p->next) {
            head = p->next;
            s = head->next;
            head->next = p;
            p->next = s;
            p = head->next;
        } else {
            return head;
        }

        while (p->next && p->next->next) {
            q = p->next->next;
            s = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            p->next = s;
        }

        return head;
    }
};