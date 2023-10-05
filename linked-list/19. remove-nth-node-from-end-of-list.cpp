struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        dummy->next = head;
        ListNode *p = dummy, *q = dummy;

        for (int i = 0; i <= n; i++) {
            q = q->next;
        }
        while (q) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;

        return dummy->next;
    }
};