#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * @brief Solution áp dụng nhanh
 * Dùng stack, duyệt qua mảng string và push vào
 * khi gặp dấu thì pop ra tính toán cho tới khi gặp dấu trước đó thì dừng lại lấy kết quả
 * tiếp tục push vào từ kết quả vừa rồi và số tiếp theo 
 * 
 * Cách nào cũng beat 100% luôn :) -> next thôi
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        if (size == 0)
        {
            return 0;
        }
        else if(size == 1)
        {
            return atoi(tokens[0].c_str());
        }
        stack<int> calStack;
        unordered_set<string> matchSet = {"+", "-", "*", "/"};
        int temp = 0;
        for(string s : tokens)
        {
            if(matchSet.find(s) == matchSet.end())
            {
                calStack.push(atoi(s.c_str()));
            }
            else
            {
                int value2 = calStack.top();
                calStack.pop();
                int value1 = calStack.top();
                calStack.pop();
                if(s == "+")
                {
                    temp = value1 + value2;
                }
                else if(s == "-")
                {
                    temp = value1 - value2;
                }
                else if(s == "*")
                {
                    temp = value1 * value2;
                }
                else if(s == "/")
                {
                    temp = value1 / value2;
                }
                calStack.push(temp);
            }
        }
        return temp; 
    }
};

int main()
{

}