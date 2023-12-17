class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        /*when we pase something using & reference then it
          would modify the actual string so the erase utility
          would not gonna effect the actual string!!*/
        if (s.size() != t.size()) return false;
        for (int i = 0; i < t.size(); i++)
        {
            size_t pos = s.find(t[i]);
            if (pos != string::npos)
            {
                s.erase(pos, 1);
                continue;
            }
            else return false;
        }
        return true;
    }
};