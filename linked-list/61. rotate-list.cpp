struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        ListNode *p = head;
        ListNode *newHead = head;
        int len = 1;

        while (p->next) {
            p = p->next;
            len++;
        }
        p->next = head;

        p = head;
        for (int i = 0; i < len - k % len - 1; i++) {
            p = p->next;
        }
        newHead = p->next;
        p->next = nullptr;

        return newHead;
    }
};