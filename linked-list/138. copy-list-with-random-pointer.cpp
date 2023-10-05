class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        
        Node *p = head;
        while (p) {
            Node *add = new Node(p->val);
            add->next = p->next;
            p->next = add;
            p = add->next;
        }

        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        p = head;
        Node *newHead = head->next;
        Node *q = newHead;
        while (p->next && q->next) {
            p->next = p->next->next;
            q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = nullptr;

        return newHead;
    }
};