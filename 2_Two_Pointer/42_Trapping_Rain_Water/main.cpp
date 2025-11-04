
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


/**
 * @brief Cách giải đơn giản (có thể nghĩ ra)
 * Chọn ví trí đầu tiên làm vách trước -> duyệt từ đầu tới cuối để tìm vách 2
 * nếu tìm được vị trí bằng hoặc lớn hơn vách trước -> xác định là vách sau -> tính ra tổng nước -> dời vách trước tới vách sau
 * 
 * Nếu mà không tìm được vách sau
 *  tìm vách thấp hơn
 *      đặt 1 vách tạm thời để lưu lại lượng nước trước vách tạm thời và sau vách tạm thời
 *  nếu có vị trí lớn hơn vách tạm thời thì cập nhật lượng nước sau vào lượng nước trước vách tạm thời
 *  duyệt đến cuối dãy, tính lượng nước trước vách tạm thời -> đưa vách trước về vách tạm thời tính tiếp
 * 
 * -> Nhược điểm quá chậm, suy nghĩ khá phức tạp 
 */
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if (height.size() < 2)
//         {
//             return 0;
//         }
//         int ret = 0;
//         int lPtr = 0;
//         int rPtr = 0;
//         int nonWaterBeforeMax = 0;
//         int nonWaterAfterMax = 0;
//         int maxHeight = 0;
//         int maxHeightIdx = 0;
//         while(lPtr < height.size() - 2)
//         {
//             rPtr++;
//             // std::cout << "check at: " << lPtr << " : " << rPtr << std::endl; 
//             if(height[lPtr] > height[rPtr])
//             {
//                 if(height[rPtr] > maxHeight)
//                 {
//                     // std::cout << "Update max height" << std::endl;
//                     nonWaterBeforeMax += nonWaterAfterMax;
//                     nonWaterAfterMax = 0;
//                     maxHeight = height[rPtr];
//                     maxHeightIdx = rPtr;
//                     nonWaterAfterMax+= height[rPtr];
//                 }
//                 else
//                 {   
//                     // std::cout << "Update after" << std::endl; 
//                     nonWaterAfterMax += height[rPtr];
//                 }

//                 if(rPtr == height.size() - 1)
//                 {
//                     // std::cout << "r reach end" << std::endl; 
//                     if (maxHeight == 0)
//                     {
//                         break;
//                     }
//                     if(maxHeightIdx > lPtr + 1)
//                     {
//                         // std::cout << "Push near Max" << height[maxHeightIdx] * (maxHeightIdx - lPtr - 1) - nonWaterBeforeMax << std::endl << std::endl; 
//                         ret += height[maxHeightIdx] * (maxHeightIdx - lPtr - 1) - nonWaterBeforeMax;
//                     }
//                     lPtr = maxHeightIdx;
//                     rPtr = maxHeightIdx;
//                     nonWaterBeforeMax = 0;
//                     nonWaterAfterMax = 0;
//                     maxHeight = 0;
//                     maxHeightIdx = 0;
//                 }
//             }
//             else
//             {
//                 // std::cout << "Height: " << height[lPtr]<< " : " << height[rPtr] << std::endl; 
//                 if(rPtr > lPtr + 1)
//                 {
//                     // std::cout << "Push max: " << height[lPtr] * (rPtr - lPtr - 1) - nonWaterBeforeMax - nonWaterAfterMax << std::endl; 
//                     ret += height[lPtr] * (rPtr - lPtr - 1) - nonWaterBeforeMax - nonWaterAfterMax;
//                 } 
//                 nonWaterBeforeMax = 0;
//                 nonWaterAfterMax = 0;
//                 maxHeight = 0;
//                 maxHeightIdx = 0;
//                 lPtr = rPtr;
//             }
//         }
//         return ret;
//     }
// };

/**
 * @brief Phương án tối ưu hơn
 * Vị trí tại i có thể hướng nước nếu tìm được 2 vách cao hơn chiều cao của nó
 * > duyệt qua từ i và tìm cách của tụi nó theo 2 pointer trước sau
 * 
 * -> Nhược điểm: chạy chậm hơn cả cách đầu 
 * Lý do: mỗi một điểm chúng ta phải duyệt cả trước và sau để tìm 2 vách -> On^3
 * -> ý tưởng là tốt nhưng triển khai chưa tốt
 */

// class Solution
// {
// public:
//     int trap(vector<int>& height) {
//         int size = height.size();
//         if (size < 3)
//         {
//             return 0;
//         }
//         int ret = 0;
//         for(int i = 1; i < size - 1; i++)
//         {
//             int lPtr = i - 1;
//             int rPtr = i + 1;
//             int maxLeft = 0;
//             int maxRight = 0;
//             while(lPtr >= 0)
//             {
//                 maxLeft = max(maxLeft, height[lPtr]);
//                 lPtr--;
//             }
//             while (rPtr < size)
//             {
//                 maxRight = max(maxRight, height[rPtr]);
//                 rPtr++;
//             }
//             int trap = min(maxLeft, maxRight);
//             std::cout << "check at: "<< std::endl; 
//             std::cout << height[i] << std::endl; 
//             std::cout << maxLeft << std::endl; 
//             std::cout << maxRight << std::endl; 
//             if (trap > height[i])
//             {
//                 std::cout << "push: "<< (trap - height[i]) << std::endl; 
//                 ret += (trap - height[i]);
//             }
//         }
//         return ret;
//     }
// };

/**
 * @brief Phương án tốt nhất
 * Đặt 2 pointer ở đầu và cuối xem như 2 vách
 * vách nào thấp hơn, thì di chuyển lên 1 
 *  -> tìm được vị trí thấp hơn cả vách vừa rồi -> tính được nước 
 *  -> không tìm được, cập nhật lại vách 
 * 
 * -> O(n) quá là ngon (yeah beat 100%)
 */


// Trong tất cả những bài toán, điểm mấy chốt là tìm điều kiện để pointer nào sẽ chạy :D

class Solution
{
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size < 3)
        {
            return 0;
        }
        int ret = 0;
        int lPtr = 0;
        int rPtr = size - 1;
        int maxLeft = height[lPtr];
        int maxRight = height[rPtr];
        while(lPtr < rPtr)
        {
            if(height[lPtr] < height[rPtr])
            {
                lPtr++;
                if(height[lPtr] < maxLeft)
                {
                    ret += maxLeft - height[lPtr];
                }
                else
                {
                    maxLeft = height[lPtr];
                }
            }
            else
            {
                rPtr--;
                if(height[rPtr] < maxRight)
                {
                    ret += maxRight - height[rPtr];
                }
                else
                {
                    maxRight = height[rPtr];
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> testcase = {4,2,0,3,2,5};
    Solution s1;
    std::cout << s1.trap(testcase) << std::endl;
}

