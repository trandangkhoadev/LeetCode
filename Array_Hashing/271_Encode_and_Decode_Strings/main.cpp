#include <iostream>
#include <string>
#include <vector>
using namespace std;


// class Solution {
// public:

//     string encode(vector<string>& strs) {
//         string ret;
//         for(auto &s : strs)
//         {
//             ret += to_string(s.size()) + "#" + s;
//         }
//         return ret;
//     }

//     vector<string> decode(string s) {
//         vector<string> ret;
//         while(s.size()> 0)
//         {
//             int subStrIndex = s.find('#');
//             string subStringLength = s.substr(0, subStrIndex);
//             int subLength = stoi(subStringLength);
//             string subString = s.substr(subStrIndex + 1, subLength);
//             ret.push_back(subString);
//             s = s.substr(subStrIndex + subLength + 1);
//         }
//         return ret;
//     }
// };

/**
 * @brief Cách 2 sử dụng binary encoding
 * Idea: mỗi một ký tự sẽ luôn được biểu diễn dưới 2 byte, cho dù có là ký tự đặc biệt
 * vì vậy ta sẽ quy định, 4 byte đầu là length và mỗi 2 byte là 1 ký tự
 * ? tại sao không để 2 byte đầu là length cho ngắn gọn -> lúc đó chỉ có thể lưu trữ tối đa 65k ký tự 
 * 
 */

class Solution
{
public: 
    string encode(vector<string> &strs)
    {
        string ret;
        for(auto& s : strs)
        {
            uint32_t length = s.size();
            // 10  - 00 00 00 0A nếu muốn push back thì phải đưa vào 00 -> 00 -> 00 -> 0A
            for(int i = 4; i-- > 0;)
            {
                ret.push_back((length >> (i * 8)) & 0xFF);
            }
            for(char c: ret)
            {

            }

            for(char c : s)
            {
                ret.push_back(c);
            }
        }
        return ret;
    }
    vector<string> decode(string s)
    {
        vector<string> ret;
        while(s.size() > 0)
        {
            uint32_t lengthOfSubString = 0;
            for(int i = 0; i < 4; i++)
            {
                lengthOfSubString = lengthOfSubString | (s[i] << 8 * (4 - i -1));
            }
            string subStr = s.substr(4, lengthOfSubString);
            s = s.substr(4 + lengthOfSubString);
            ret.push_back(subStr);
        }
        return ret; 
    }
};

int main()
{
    vector<string> testcase1 = {"VeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimesVeryLongStringWithoutAnySpacesOrSpecialCharactersRepeatedManyTimes"};
    Solution s1;
    string encode = s1.encode(testcase1);
    vector<string> decode = s1.decode(encode);
}