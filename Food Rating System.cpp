// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <set>
#include <bits/stdc++.h>

using namespace std;

class FoodRatings
{
    // map for storing the food : rating
    unordered_map<string, int> frMap;
    // map for storing cuisine : food
    unordered_map<string, string> fcMap;
    // map for combo of above maps
    unordered_map<string, set<pair<int, string>>> combo;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            frMap[foods[i]] = ratings[i];
            fcMap[foods[i]] = cuisines[i];
            combo[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        auto cuisineName = fcMap[food];
        // deleting the old food and its rating
        auto deleteOldRatings = combo[cuisineName].find({-frMap[food], food});
        combo[cuisineName].erase(deleteOldRatings);
        frMap[food] = newRating;
        combo[cuisineName].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        auto hr = *combo[cuisine].begin();
        return hr.second;
    }
};

int main()
{
    //example object for testing 
    vector<string> foods = {"chicken", "raita", "salad"};
    vector<string> cuisines = {"nihari", "extra", "extra"};
    vector<int> ratings = {5, 3, 3};

    FoodRatings *t1 = new FoodRatings(foods, cuisines, ratings);
    cout << t1->highestRated("nihari") << endl;

    delete t1; // Remember to free the memory allocated for the object
    return 0;
}
