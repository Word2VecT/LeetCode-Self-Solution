struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        ListNode *q, *s;

        while (p) {
            q = p;
            while (q) {
                if (q->next && q->next->val == p->val) {
                    s = q->next->next;
                    delete q->next;
                    q->next = s;
                } else {
                    q = q->next;
                }
            }
            p = p->next;
        }
        return head;
    }
};