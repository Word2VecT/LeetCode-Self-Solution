#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int turn = time / (n - 1);
        if (turn % 2 == 0) {
            return 1 + time % (n - 1);
        } else {
            return n - time % (n - 1);
        }
    }
};