#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

/**
 * @brief Quick solution
 * Tìm ở giữa, nếu target nhỏ hơn thì tìm ở giữa phần bên trái
 * Nếu target lớn hơn thì tìm ở giữa phần bên phải
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int r = nums.size() - 1;
        int l = 0;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {5};
    Solution s1;
    
    std::cout << s1.search(nums, 5) << std::endl; 
}