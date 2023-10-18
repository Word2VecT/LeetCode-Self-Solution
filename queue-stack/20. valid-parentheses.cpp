#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> parent;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parent.push(c);
            } else {
                if (c == ')') { 
                    if (!parent.empty() && parent.top() == '(') {
                        parent.pop();
                    } else {
                        return false;
                    }
                }
                if (c == '}') {
                    if (!parent.empty() && parent.top() == '{') {
                        parent.pop();
                    } else {
                        return false;
                    }
                }
                if (c == ']') {
                    if (!parent.empty() && parent.top() == '[') {
                        parent.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return parent.empty();
    }
};