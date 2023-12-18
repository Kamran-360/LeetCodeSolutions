#include <bits/stdc++.h>
using namespace std;
// creating a trace map to hold the adjacent pairs frequency
map<string, int> Tmap;
int main()
{
    int n, m = 0;  string s, c, tgPair;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        c= s.substr(i,2);
        Tmap[c]++;
        if (Tmap[c] > m)
            m = Tmap[c],tgPair = c;
    }
    cout << tgPair <<"\n";

    return 0;
}

/*
problem : https://codeforces.com/contest/977/problem/B
*/
