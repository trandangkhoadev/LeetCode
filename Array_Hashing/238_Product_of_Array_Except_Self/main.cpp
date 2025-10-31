
#include <vector>
#include <iostream>

using namespace std;


/**
 * @brief O(n) và không sử dụng  phép chia
 * Duyệt mảng từ đầu đến cuối, tính được tích bên trái của index
 * Duyệt mảng từ cuối đến đầu, tính dược tích bên phải của index
 * Nhân trái và phải ta được kết quả
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size, 1);
        // int leftvalue = 1;
        int rightvalue = 1;
        for(int i = 1; i < size; i++)
        {
            // leftvalue = leftvalue * nums[i-1];
            ret[i] = ret[i -1] * nums[i-1];
        }
        for(int j = size - 2; j >= 0; j--)
        {
            rightvalue = rightvalue * nums[j+1];
            ret[j] = ret[j] * rightvalue;
        }
        return ret;
    }
};

int main()
{
    vector<int> testcase1 = {1,2,4,6};
    vector<int> testcase2 = {-1,0,1,2,3};

    // 1 1 2 8
    //     12   8
    Solution s1;
    s1.productExceptSelf(testcase2);
}