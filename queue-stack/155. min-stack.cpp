#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> normStack;
    std::stack<int> minStack;

public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        normStack.push(val);
        minStack.push(std::min(val, minStack.top()));
    }
    
    void pop() {
        normStack.pop();
        minStack.pop();
    }
    
    int top() {
        return normStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */