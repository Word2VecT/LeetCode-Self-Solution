struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *p = head;
        ListNode *mid = head;
        ListNode *q, *s;
        int len = 0;
        int cnt, temp;

        while (p) {
            len++;
            p = p->next;
        }

        cnt = (len - 1) / 2;
        for (int i = 0; i < cnt; i++) {
            mid = mid->next;
        }

        q = mid->next;
        mid->next = nullptr;
        while (q) {
            s = q;
            q = q->next;
            s->next = mid->next;
            mid->next = s;
        }

        p = head->next;
        q = mid->next;
        s = head;
        temp = 0;
        while (q) {
            s->next = q;
            q = q->next;
            s = s->next;
            if (++temp <= cnt) {
                s->next = p;
                p = p->next;
                s = s->next;
            }
        }
        s->next = nullptr;
    }
};