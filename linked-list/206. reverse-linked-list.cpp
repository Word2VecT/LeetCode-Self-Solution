struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = head;
        ListNode *q;

        while (p) {
            q = p;
            p = p->next;
            q->next = dummy->next;
            dummy->next = q;
        }

        head = dummy->next;
        delete dummy;

        return head; 
    }
};