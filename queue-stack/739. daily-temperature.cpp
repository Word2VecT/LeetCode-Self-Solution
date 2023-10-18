#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int len = temperatures.size();
        std::stack<int> index;
        std::vector<int> gap(len);
        
        for (int i = 0; i < len; i++) {
            while (!index.empty() && temperatures[index.top()] < temperatures[i]) {
                gap[index.top()] = i - index.top();
                index.pop();
            }
            index.push(i);
        }
        return gap;
    }
};