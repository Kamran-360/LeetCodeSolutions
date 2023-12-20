#include <bits/stdc++.h>
using namespace std;

/*
problem :https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
*/
class Solution
{
public:
    int method_One(string s)
    {
        unordered_set<char> track;
        int m = 0, l = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (track.count(s[i]) == 0)
            {
                track.insert(s[i]);
                m = max(m, (i + 1) - l);
            }
            else
            {
                while (track.count(s[i]))
                {
                    track.erase(s[l]);
                    l++;
                }
                track.insert(s[i]);
            }
        }
        return m;
    }
    // More efficient and short method (less complexity)
    int method_Two(string s)
    {

        int n = s.length();
        int m = 0;
        vector<int> f(128, -1);
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            if (f[s[r]] >= l)
            {
                l = f[s[r]] + 1;
            }
            f[s[r]] = r;
            m = max(m, r - l + 1);
        }

        return m;
    }
};

int main()
{
    // example
    Solution *t = new Solution();
    cout << t->method_One("abcdefatr") << endl;
    cout << t->method_Two("abcdefatr") << endl;
    return 0;
}

/*
method_One explaination: keep storing the elements in set if they are comming as distinct,
the moment we get the element which is present in the set already then it means we have
to subtract the elements in the set till that already placed element found and we have to
remove it too, and so on.Variable l would the number of elements we removed so far.(inside
while loop we calculate l).i is the total elements encountered so far so remove the l from
i to get the current length of substring we are working on.its just like =>{1 2 3 4 5 6 7}
(if starting from index 1) if  we want to deal with the index 3 then we have to remove (n - 3)
gives the index 4 so it means the current length up to the newly added elem is 4 without any
repeatitions yet.(remember l is also acting as ponter pointing to the latest element where we
have to start the removal of elements till the already found element)
*/

/*
method_Two explaination: creating a vector of capacity 128(for Max ASCII for alphabets)
then initializing the values with -1 and then keep updating m if the distinct elements is
encoutering and store the index of the element in vector at their corresponding ascii
i.e a has ascii 97 if it is comming at index 4 then at index 97 of vector the value would be 4
if it becomes greater than the -1 it means it has already encoutered and the element is repeating
so substract the l from m and updating it usng max and keep doing untill the loop condition
becomes false the resulted sub string would be the longest substring with no repeatition.
*/
//hope you got it buddy!
