struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }

        ListNode *p = head->next->next;
        ListNode *q;
        if (p->next) {
            q = p->next->next;
        } else {
            q = nullptr;
        }

        ListNode *oddEnd = head;
        ListNode *evenEnd = head->next;

        while (p) {
            evenEnd->next = p->next;
            p->next = oddEnd->next;
            oddEnd->next = p;
            oddEnd = p;
            evenEnd = evenEnd->next;

            if (q) {
                p = q;
                if (q->next) {
                    q = q->next->next;
                } else {
                    q = nullptr;
                }
            } else {
                p = nullptr;
            }
        }

        return head;
    }
};

// ! 题解是先分奇偶归并，再 merge