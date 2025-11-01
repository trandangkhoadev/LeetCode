
#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief Solution On
 * tạo 1 stack (last in first out)
 * cơ chế là gặp mở ngoặc thì push vào, gặp đóng ngoặc thì pop các mở ngoặc vừa push ra
 * cuối cùng nếu stack rỗng là đúng
 * 
 * -> Cách này đã beat 100%, có thể optimise để gọn code hơn
 */

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> myStack;
//         for(const auto& c : s)
//         {
//             if(c == '('|| c == '[' || c == '{')
//             {
//                 myStack.push(c);
//             }
//             else if (myStack.empty())
//             {
//                 return false;
//             }
//             else 
//             {
//                 char top = myStack.top();
//                 if((c == ')') && (top == '('))
//                 {
//                     myStack.pop();
//                 }
//                 else if((c == '}') && (top == '{'))
//                 {
//                     myStack.pop();
//                 }
//                 else if((c == ']') && (top == '['))
//                 {
//                     myStack.pop();
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//         }
//         if(myStack.size() !=0)
//         {
//             return false;
//         }
//         return true;
//     }
// };

/**
 * @brief Cách trên nhưng optimise
 * Sử dụng 1 map để tra cứu đã tốn effort if else
 * 
 */

class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> parenStack;
        unordered_map<char, char> checkMap =
        {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        for(const char& c : s)
        {
            if(checkMap.find(c) != checkMap.end())
            {
                parenStack.push(c);
            }
            else if(parenStack.empty())
            {
                return false;
            }
            else
            {
                char top = parenStack.top();
                if(checkMap[top] != c)
                {
                    return false;
                }
                else
                {
                    parenStack.pop();
                }
            }
        }
        if(!parenStack.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    string testcase1 = "()";
    Solution s1;
    s1.isValid(testcase1);
}