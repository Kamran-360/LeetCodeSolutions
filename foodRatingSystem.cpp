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
//Problem Statement
/* Design a food rating system that can do the following:
Modify the rating of a food item listed in the system.
Return the highest-rated food item for a type of cuisine in the system.
Implement the FoodRatings class:
FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
foods[i] is the name of the ith food,
cuisines[i] is the type of cuisine of the ith food, and
ratings[i] is the initial rating of the ith food.
void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.
Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.*/
