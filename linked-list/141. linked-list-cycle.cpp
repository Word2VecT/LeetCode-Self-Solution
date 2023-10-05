struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;

        while (q && q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                return true;
            }
        }

        return false;
    }
};