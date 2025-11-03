

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief Solution
 * sort lại 
 * chọn đầu và cuối tìm thằng thứ 3
 * nếu 3sum điều lớn hơn 0 -> đang quá lớn, giảm thằng cuối
 * nếu 3 sum nhỏ hơn 0 -> đang quá nhỏ, tăng thằng đầu 
 * 
 * -> Thuật toán này sai rồi:
 *  nếu 3Sum = 0 thì xử lý thế nào, tiếp tục thăng third lên thì vô nghĩa
 *  nếu break ra thì bị mất tổ hợp
 *  nếu tăng lptr hoặc rptr cũng gây ra mất tổ hợp
 *  bonus thêm một lỗi là không xử lý trường hợp duplicate
 * 
 * -> Chỗ này phương án đúng là cố định 1 thằng
 * rồi đặt lptr, rptr để tìm sum3, tìm hết khả năng (l gặp r) thì mới tăng thằng cố định lên
 * Xử lý duplicate: khi thì cố định tiếp theo bằng thằng cố định vừa rồi thì bỏ qua, do chúng ta đã tìm 
 * ở thằng trước đó các bộ 3 rồi, tìm tiếp là duplicate
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if ((i > 0) && (nums[i] == nums[i-1]))
            {
                continue;
            }
            int lptr = i + 1;
            int rptr = nums.size() - 1;
            while (lptr < rptr)
            {
                int sum3 = nums[i] + nums[lptr] + nums[rptr];
                if(sum3 > 0)
                {
                    rptr--;
                }
                else if (sum3 == 0)
                {
                    ret.push_back({nums[i], nums[lptr], nums[rptr]});
                    rptr--;
                    lptr++;
                    while (lptr < rptr && nums[lptr] == nums[lptr - 1]) 
                        lptr++;
                    while (lptr < rptr && nums[rptr] == nums[rptr + 1]) 
                        rptr--;
                }
                else
                {
                    lptr++;
                }
            }
            
        }
        return ret;
    }
};


int main()
{
    vector<int> testcase1 = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    Solution s1;
    s1.threeSum(testcase1);
}