#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    string longestCommonPrefix(vector<string> &s)
    {
        int l = s.size();
        int m = 1e5;
        int index;
        for (int i = 0; i < l; i++)
        {
            int cl = s[i].length();
            if (cl < m)
            {
                m = cl;
                index = i;
            }
        }
        string cStr = s[index];
        // s.erase(s.begin() + index);
        // checking the things in here
        for (int i = 0; i < l; i++)
        {
            int r = 0;
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == cStr[j])
                {
                    r++;
                }
                else break;
            }
            cout << r << endl;
            m = r;
        }
        return cStr.substr(0, m);
    }
};

int main()
{
    Solution *t = new Solution();
    vector<string> p = {"cir","car"};
    cout << t->longestCommonPrefix(p);
    return 0;
}
//problem : https://leetcode.com/problems/longest-common-prefix/
