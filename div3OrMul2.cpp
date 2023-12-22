#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<pair<int, long long>> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        long long o = x;
        int c = 0;
        while (o % 3 == 0)
        {
            c++;
            o /= 3;
        }
        s.insert({-c, x});
    }
    for (auto i : s)
    {

        cout << i.second << " ";
    }
    return 0;
}

/*
6
4 8 6 3 12 9
Output
9 3 6 12 4 8
*/
