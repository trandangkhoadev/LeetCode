
#include <vector>
#include <stack>
#include <iostream>

using namespace std;


/**
 * @brief Quick solution
 * Chọn 1 phần tử, duyệt sang trái và phải để tìm S lơn nhất
 * lặp lại để duyệt qua tất cả các phần tử 
 * -> tìm được lớn nhất (On^2)
 * 
 * -> Suy nghĩ xem có cách nào tìm được giới hạn mà không cần duyệt thủ công On^2 không
 * 
 * Mấu chốt của bài toán này là suy nghĩ được 
 *  khi xét 1 cột, ta chắc chắn tính được diện tích của nó (diện tích của hình có chiều cao h = heights[i])
 *      -> gặp thằng nhỏ hơn đầu tiên bên phải, và gặp thằng nhỏ hơn đầu tiên bên trái
 *  Duyệt từ trái sang phải ta tính được diện tích các hình có chiều cao, heights[i] bằng cách tìm 2 điểm chặn trái và phải
 *      - đặt 2 chặn đầu tiên và cuối cùng là height = 0
 *      - duyệt từ height[0] -> cuối.
 *      - nếu nếu gặp chiều cao lớn hơn push vào trong stack (vì nó vẫn không phải là chặn của chiều cao trước đó)
 *      - nếu gặp thằng nhỏ hơn (ta tìm được chặn phải, và tiếp tục pop để tìm chặn trái -> tính ra được s)
 *      - nếu gặp thằng bằng, thì không làm gì
 * - stack chứa index
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if(size < 2)
        {
            return (size == 0) ? 0 : heights[size - 1];
        }

        vector<int> modifiedHeights; 
        modifiedHeights.push_back(0);
        for(auto&ins: heights)
        {
            modifiedHeights.push_back(ins);
        }
        modifiedHeights.push_back(0);

        int largest = 0;
        stack<int> tallerIndexStack;
        tallerIndexStack.push(0);
        for(int i = 1; i < size + 2; i++)
        {
            // std::cout << "check: " << i << " | "<< modifiedHeights[i] <<" vs "<< modifiedHeights[tallerIndexStack.top()] << std::endl; 
            while (modifiedHeights[i] < modifiedHeights[tallerIndexStack.top()])
            {
                int height = modifiedHeights[tallerIndexStack.top()];
                // std::cout << "height: " << height << std::endl; 
                while(modifiedHeights[tallerIndexStack.top()] == height)
                {
                    tallerIndexStack.pop();
                }
                // std::cout << "i: " << i << std::endl; 
                // std::cout << "tallerIndexStack.top(): " << tallerIndexStack.top() << std::endl; 
                int s = height * (i - tallerIndexStack.top() - 1);
                // std::cout << "s: " << s << std::endl; 
                largest = max(s, largest);
            }
            tallerIndexStack.push(i);
        }
        return largest;
    }
};

int main()
{
    vector<int> height = {2,1,4,5,1,3,3};
    Solution s1;
    s1.largestRectangleArea(height);
}