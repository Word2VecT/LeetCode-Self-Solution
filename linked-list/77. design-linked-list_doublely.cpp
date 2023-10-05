#include <algorithm>

struct ListNode {
    int val;
    ListNode *prev, *next;
    ListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0);
        this->tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode *p = head;
        for (int i = 0; i <= index; i++) {
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }

        index = std::max(0, index);
        size++;

        ListNode *add = new ListNode(val);
        ListNode *p;

        if (index + 1 < size - index) {
            p = head;
            for (int i = 0; i <= index; i++) {
                p = p->next;
            }
        } else {
            p = tail;
            for (int i = 0; i < size - index; i++) {
                p = p->prev;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        size--;

        ListNode *p, *temp;

        if (index + 1 < size - index) {
            p = head;
            for (int i = 0; i <= index; i++) {
                p = p->next;
            }
        } else {
            p = tail;
            for (int i = 0; i < size - index; i++) {
                p = p->prev;
            }
        }

        temp = p;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete temp;
    }
private:
    int size;
    ListNode *head;
    ListNode *tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */