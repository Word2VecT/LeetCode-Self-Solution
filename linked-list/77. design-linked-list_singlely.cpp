#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0);
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
        ListNode *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        add->next = p->next;
        p->next = add;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        size--;

        ListNode *p = head;
        ListNode *temp;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        delete temp;
    }
private:
    int size;
    ListNode *head;
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