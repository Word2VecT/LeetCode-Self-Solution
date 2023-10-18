#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> num;
        for (auto token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                num.push(stoi(token));
            } else {
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                if (token == "+") {
                    num.push(a + b);
                }
                if (token == "-") {
                    num.push(a - b);
                }
                if (token == "*") {
                    num.push(a * b);
                }
                if (token == "/") {
                    num.push(a / b);
                }
            }
        }
        return num.top();
    }
};