#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> plusone;
        int l = digits.size() - 1;
        int p = l;
        for (l; l >= 0; l--)
        {
            if (digits[l] == 9)
                continue;
            break;
        }

        int ansL = digits.size();
        if (l < 0)
        {
            vector<int> ans(ansL+1,0);
            ans[0] = 1;
            plusone = ans;
        }
        else
        {
            bool flag = false;
            vector<int> ans(ansL,0);
            for (int i = 0; i < ansL; i++)
            {
                if (i == l)
                {
                    ans[l] = digits[l] + 1; break;
                }
                ans[i] = digits[i];
            }
            plusone = ans;
        }
        return plusone;
    }
//Second method
vector<int> plusOne2(vector<int>& v) {
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1) v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0) v[i-1]++;
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }

};

int main()
{
    Solution *t = new Solution();
    vector<int> p = {9,1,2,3,6};
    t->plusOne(p);
}
//problem : https://leetcode.com/problems/plus-one/description/
/* you might wonder the second one is small and any would definitely be more efficient.But guess what the first method's rutime is 0ms 
while the runtime of second methos is approx 4ms with little more memory usage than the first. */
