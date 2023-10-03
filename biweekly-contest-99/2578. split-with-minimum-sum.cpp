#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    string str = to_string(num);
    sort(str.begin(), str.end());
    int num0 = 0, num1 = 0;
    for (int i = 0; i < str.size(); i++) {
        if (i % 2) {
            num0 = num0 * 10 + str[i] - '0';
        } else {
            num1 = num1 * 10 + str[i] - '0';
        }
    }

    cout << num0 + num1 << '\n';

    return 0;
}