/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.insert(num).second != true)
            {
                return true;
            }   
        }
        return false;
    }
};

int main()
{
    vector<int> tc1 = {1,2,3,1};
    vector<int> tc2 = {1,2,3,4};
    vector<int> tc3 = {1,1,1,3,3,4,3,2,4,2};
    Solution s1;
    cout << (s1.containsDuplicate(tc1) ? "Duplicated \n" : "No duplicate\n");
    cout << (s1.containsDuplicate(tc2) ? "Duplicated \n" : "No duplicate\n");
    cout << (s1.containsDuplicate(tc3) ? "Duplicated \n" : "No duplicate\n");
    return 0;
}