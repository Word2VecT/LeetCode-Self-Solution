#include <queue>

class MyStack {
private:
    std::queue<int> queue0;
    std::queue<int> queue1;

public:
    MyStack() {}
    
    void push(int x) {
        queue1.push(x);
        while (!queue0.empty()) {
            queue1.push(queue0.front());
            queue0.pop();
        }
        std::swap(queue0, queue1);
    }
    
    int pop() {
        int tmp = queue0.front();
        queue0.pop();
        return tmp;
    }
    
    int top() {
        return queue0.front();
    }
    
    bool empty() {
        return queue0.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */