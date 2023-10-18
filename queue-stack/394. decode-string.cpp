#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<char> decode;
        for (auto c : s) {
            if (c == ']') {
                std::string repeat;
                while (!decode.empty() && decode.top() != '[') {
                    repeat.push_back(decode.top());
                    decode.pop();
                }
                decode.pop();

                std::stack<char> digit;
                while (!decode.empty() && isdigit(decode.top())) {
                    digit.push(decode.top());
                    decode.pop();
                }

                int cnt = 0;
                while (!digit.empty()) {
                    cnt = cnt * 10 + digit.top() - '0';
                    digit.pop();
                }

                int len = repeat.size();
                for (int i = 0; i < cnt; i++) {
                    for (int j = len - 1; j >= 0; j--) {
                        decode.push(repeat[j]);
                    }
                }
            } else {
                decode.push(c);
            }
        }

        std::string ans;
        while (!decode.empty()) {
            ans.push_back(decode.top());
            decode.pop();
        }
        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};