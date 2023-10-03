#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        constexpr int mod = 1E9 + 7;

        sort(ranges.begin(), ranges.end(), [&](vector<int>& a, vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        });

        long long b = 0;
        int loc = -2;
        for (int i = 0; i < ranges.size(); i++) {
            if (ranges[i][1] > loc) {
                if (ranges[i][0] > loc) {
                    b++;
                }
                loc = ranges[i][1];
            }
        }

        long long a = 2;
        long long res = 1;
        for (; b; b >>= 1, a = a * a % mod) {
            if (b % 2) {
                res = res * a % mod;
            }
        }

        return res;

    }
};