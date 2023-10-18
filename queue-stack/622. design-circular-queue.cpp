#include <vector>

class MyCircularQueue {
private:
    int front;
    int rear;
    int capacity;
    int *base;

public:
    MyCircularQueue(int k) {
        this->capacity = k + 1;
        this->base = new int[capacity];
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        base[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return base[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return base[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */