struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode *p = head;
        ListNode *mid = head;
        ListNode *q;
        int len = 0;
        int cnt;

        while (p) {
            len++;
            p = p->next;
        }

        for (int i = 0; i <= (len - 1) / 2; i++) {
            mid = mid->next;
        }

        ListNode *dummy = new ListNode(0);
        p = head;
        for (int i = 0; i < len / 2; i++) {
            q = p;
            p = p->next;
            q->next = dummy->next;
            dummy->next = q;
        }

        p = dummy->next;
        q = mid;
        while (q) {
            if (p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }

        delete dummy;

        return true;
    }
};