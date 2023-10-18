#include <stack>

class MyQueue {
private:
    std::stack<int> headFirstStack;
    std::stack<int> tearFirstStack;

public:
    MyQueue() {}
    
    void push(int x) {
        while (!headFirstStack.empty()) {
            tearFirstStack.push(headFirstStack.top());
            headFirstStack.pop();
        }
        tearFirstStack.push(x);
        while (!tearFirstStack.empty()) {
            headFirstStack.push(tearFirstStack.top());
            tearFirstStack.pop();
        }
    }
    
    int pop() {
        int tmp = headFirstStack.top();
        headFirstStack.pop();
        return tmp;
    }
    
    int peek() {
        return headFirstStack.top();
    }
    
    bool empty() {
        return headFirstStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */ 