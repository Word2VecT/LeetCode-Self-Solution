struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode preHead;
        preHead.next = head;
        ListNode *p = &preHead;
        ListNode *s;

        while (p->next) {
            if (p->next->val == val) {
                s = p->next->next;
                delete p->next;
                p->next = s;
            } else {
                p = p->next;
            }
        }

        return preHead.next;
    }
};