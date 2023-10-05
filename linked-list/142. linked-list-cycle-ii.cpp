struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;

        bool hasCycle = false;

        while (q && q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                hasCycle = true;
                break;
            }
        }
        
        int len = 0;

        if (hasCycle) {
            do {
                len++;
                p = p->next;
                q = q->next->next;
            } while (p != q);
        } else {
            return nullptr;        
        }

        p = head;
        q = head;
        for (int i = 0; i < len; i++) {
            q = q->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};

// TODO: 官方题解的数学推理能够少一次循环