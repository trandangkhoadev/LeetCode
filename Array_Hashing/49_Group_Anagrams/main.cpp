/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map <string, vector<string>> aliasValueMap;
//         vector<vector<string>> retVal;
//         for (auto& s: strs)
//         {
//             int cnt[26] = {0};
//             cout << "check" << s << "\n";
//             for(char c : s)
//             {
//                 cout << c << "\n";
//                 cnt[c - 97]++;
//                 cout<< c - 97 << " " << cnt[c - 97] << "\n";
//             }
//             string anagramAlias;
//             for(int i = 0; i < 26; i++)
//             {
//                 anagramAlias += string(1, cnt[i] + 'a');
//             }
//             aliasValueMap[anagramAlias].push_back(s);
//             cout << anagramAlias << "\n";
//         }
//         for(auto &ins: aliasValueMap)
//         {
//             retVal.push_back(ins.second);
//         }
//         return retVal;
//     }
// };

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> myMap;
        for(auto ins: strs)
        {
            string it = ins;
            sort(ins.begin(), ins.end());
            myMap[ins].push_back(it);
        }
        for(auto ins: myMap)
        {
            ret.push_back(ins.second);
        }
        return ret;
    }
};


int main()
{
}