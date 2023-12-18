#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, val;
    vector<int> a;
    // Read input values
    cin >> n >> k;
    // Read n integers into the vector a
    for (int i = 0; i < n; i++) {
        cin >> val;
        a.push_back(val);
    }
    //In case if k = 0 then 1 would be the obvious answer if a[k] != a[k + 1] is valid
    a.insert(a.begin(), 1);
    sort(a.begin(), a.end());
    // Output either a[k] or -1 based on the condition
    cout << (a[k] != a[k + 1] ? a[k] : -1);
}
// problem : https://codeforces.com/contest/977/problem/C
