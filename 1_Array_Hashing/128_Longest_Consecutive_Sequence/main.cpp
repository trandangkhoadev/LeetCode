#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
/**
 * @brief nLogn (sort)
 * Idea: sort vector này, sau đó duyệt từ nhỏ đến lớn, đếm xem longest và return
 * 
 */ 
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         std::sort(nums.begin(), nums.end());
//         int longest = 0;
//         int temp = 1;
//         for(int i = 0; i < nums.size() - 1; i++)
//         {
//             if(nums[i] == nums[i + 1])
//             {
//                 continue;
//             }
//             if(nums[i] + 1 == nums [i + 1])
//             {
//                 temp++;
//                 if (temp > longest)
//                 {
//                     longest = temp;
//                 }
//             }
//             else
//             {
//                 temp = 1;
//             }
//         }
//         return longest;
//     }
// };


/**
 * @brief Phương án O(n)
 * tìm max On
 * tạo ra mảng với max phần tử, thể hiện sự xuất hiện của các số
 * duyệt qua mảng tìm longest On
 * -> :) điểm yếu trí mạng của phương án này, nếu có số âm thì cút :D
 */
// class Solution
// {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int max = 0;
//         for(auto& ins: nums)
//         {
//             if (ins > max)
//             {
//                 max = ins;
//             }
//         }
//         vector<bool> indexAlive (max + 1, false);
//         for(auto& ins: nums)
//         {
//             indexAlive[ins] = true;
//         }
//         int temp = 0;
//         int longest = 0;
//         for(auto ins: indexAlive)
//         {
//             std::cout << ins << std::endl; 
//             if(ins == true)
//             {
//                 temp++;
//                 if(temp > longest)
//                 {
//                     longest = temp;
//                 }
//             }
//             else
//             {
//                 temp = 0;
//             }
//         }
//         return longest;
//     }
// };

/**
 * @brief Phương pháp On thật sự
 * vẫn chép mảng vào 1 unorderset
 * duyệt qua unorder_set
 * - nếu phần tử x là đầu chuỗi, thì bắt đầu + lên 1 và count 
 * - nếu phần từ x là giữa chuỗi (tồn tại x - 1 trong set) -> thì không check nữa
 * 
 * -> Phương án này beat 75%, nếu dùng find thì nhanh hơn
 */
class Solution
{
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> charactor(nums.begin(), nums.end());
        int longest = 0;
        for(auto& ins: charactor)
        {
            if(charactor.count(ins - 1) != true)
            {
                int temp = 1;
                int step = 1;
                while(charactor.count(ins + step))
                {
                    step++;
                    temp++;
                }
                if(temp > longest)
                {
                    longest = temp;
                }
            }
        }
        return longest;
    }
};




int main()
{
    vector<int> testcase1 = {0,3,7,2,5,8,4,6,0,1};
    Solution s1;
    int ret = s1.longestConsecutive(testcase1);
    // std::cout << ret << std::endl; 
}