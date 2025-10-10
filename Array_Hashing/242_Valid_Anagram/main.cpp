/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        int cnt[26];
        for(int i = 0; i < s.size(); i++)
        {
            cnt[s[i] - 97]++;
            cnt[t[i] - 97]--;
        }   
        for(auto &i : cnt)
        {
            if (i!=0)
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{

}
