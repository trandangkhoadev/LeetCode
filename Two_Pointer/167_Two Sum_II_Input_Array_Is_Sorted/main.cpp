
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief phương án On -> beat 100%
 * tạo 1 unorder_map để lưu lại giá trị và index
 * duyệt qua mảng, nếu trong map có giá trị nào + với giá trị đang set bằng target -> return index
 * nếu không có thì ghi giá trị và index vào map
 * 
 * Tuy nhiên đây là bài toán two pointer thì có thể giải theo two pointer
 */
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         unordered_map<int, int> valueIndexMap;
//         vector<int> ret;
//         for(int i = 0; i < numbers.size(); i++)
//         {   
//             if(valueIndexMap.find(target - numbers[i]) == valueIndexMap.end())
//             {
//                 valueIndexMap[numbers[i]] = i;
//             }
//             else
//             {
//                 return {valueIndexMap[target - numbers[i]] + 1, i + 1};
//             }
//         }
//         return ret;
//     }
// };

/**
 * @brief Phương pháp two pointer
 * Phương án này chỉ có thể sử dụng được với mảng đã sắp xếp
 * cho 2 con trỏ ở trái và phải
 * nếu tổng nhỏ hơn thì dịch bên trái lên, nếu tổng lớn hơn thì dịch bên phải xuống
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lptr = 0;
        int rptr = numbers.size() - 1;
        while(lptr < rptr)
        {
            int sum = numbers[lptr] + numbers[rptr];
            if(sum < target)
            {
                lptr++;
            }
            else if (sum > target)
            {
               rptr--;
            } 
            else
            {
                return {lptr +1, rptr + 1};
            }
        }
        return{0,0};
    }
};

int main()
{
    vector<int>testcase1 = {5,25,75};
    Solution s1;
    vector<int> ret = s1.twoSum(testcase1,100);
    for(auto &ins:ret)
    {
        std::cout << ins << std::endl; 
    }
}