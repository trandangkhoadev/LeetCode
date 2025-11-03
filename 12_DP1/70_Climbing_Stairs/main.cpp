#include <iostream>
#include <unordered_map>
using namespace std;


/**
 * @brief Solution đơn giản nhất để giải bài toán này
 * 
 * các trường hợp base case
 * nếu đang ở step 2 thì trước đó có thể ở 1 hoặc 2 -> 2 cách
 * f(2) = 2
 * nếu đang ở 1 thì trước đó chỉ có thể ở 0 -> 1 cách
 * f(1) = 1
 * 
 * nếu ở 3 thì trước đó có thể ở 2 và 1. ta được công thức tổng quát
 * f(n) = f(n-1) + f(n - 2)
 * 
 * Nhược điểm -> phần code dưới đây mỗi f(1), f(2), f(3) được tính đi tính lại nhiều lần
 * -> Solution dùng container nào đó lưu giá trị lại để khi gặp thì móc ra dùng
 */
// class Solution {
// private:
//     int dp(int step)
//     {
//         if(step == 2)
//         {
//             return 2;
//         }
//         else if(step == 1)
//         {
//             return 1;
//         }
//         else
//         {
//             return dp(step - 1) +  dp(step - 2);
//         }
//     }

// public:
//     int climbStairs(int n) {
//         if (n > 0)
//         {
//            return dp(n);
//         }
//         return 0;
//     }
// };

class Solution {
    
private:
    unordered_map<int, int> memoryMap;
    int dp(int step)
    {
        if(step == 2)
        {
            return 2;
        }
        else if (step == 1)
        {
            return 1;
        }
        else
        {
            if(memoryMap.count(step) != 0)
            {
                return memoryMap[step];
            }
            else
            {
                int solution = dp(step -1) + dp(step -2);
                memoryMap.insert({step, solution});
                return solution;
            }
        }
    }

public:
    int climbStairs(int n) {
        if(n > 0)
        {
            return dp(n);
        }
        return 0;
    }
};



int main()
{
    // Solution s1;
    // std::cout << s1.climbStairs(3) << std::endl; 
}