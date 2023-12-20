#include <bits/stdc++.h>
using namespace std;

/*
problem :https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
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
            else{
                while(track.count(s[i])){
                    track.erase(s[l]);
                    l++;
                }
                track.insert(s[i]);
            }
        }
        return m;
    }
};

int main()
{
    //example
    Solution *t = new Solution();
    t->lengthOfLongestSubstring("abcdefatr");
    return 0;
}

/*
Example explaination: keep storing the elements in set if they are comming as distinct,
the moment we get the element which is present in the set already then it means we have 
to subtract the elements in the set till that already placed element found and we have to 
remove it too, and so on.Variable l would the number of elements we removed so far.(inside 
while loop we calculate l).i is the total elements encountered so far so remove the l from 
i to get the current length of substring we are working on.its just like =>{1 2 3 4 5 6 7}
(if starting from index 1) if  we want to deal with the index 3 then we have to remove (n - 3) 
gives the index 4 so it means the current length up to the newly added elem is 4 without any 
repeatitions yet.(remember l is also acting as ponter pointing to the latest element where we 
have to start the removal of elements till the already found element)
hope you got it buddy!
*/ 

