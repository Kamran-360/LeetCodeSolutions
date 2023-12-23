class Solution
{
public:
    bool isPathCrossing(string path)
    {
        //contains all the unique points visited so far
        set<pair<int,int>> points;
        points.insert({0,0}); //we are at origin right now
        int x = 0,y = 0;
        for(auto p : path){
            if(p == 'N') y++;
            else if(p == 'S') y--;
            else if(p == 'E') x++;
            else x--;
            if(points.find({x,y}) != points.end()) return true;//if the point has already been visited!
            points.insert({x,y}); //else insert back the unique point
        }
        return false;//return false if no loop has found!
    }
};


//problem : https://leetcode.com/problems/path-crossing/
