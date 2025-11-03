
#include <vector>
#include <math.h>
using namespace std;

/**
 * @brief O(n^2) phương pháp đơn giản nhẩt
 * Lấy 1 vị trí làm gốc, tính diện tích với tất cả các cột còn lại
 * Tiếp tục thay đổi vị trí gốc đến hết mảng, -> tìm được max
 * 
 * -> Nhược điểm, quá rõ ràng On^2
 */

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxS = 0;
//         for(int i = 0; i < height.size(); i++)
//         {
//             for(int j = 0; j < height.size(); j++)
//             {
//                 int temp = abs((i - j) * min(height[i], height[j]));
//                 maxS = max(temp, maxS);
//             }
//         }
//         return maxS;
//     }
// };


/**
 * @brief Phương án tối ưu hơn two pointer
 * Đặt 2 điểm đầu và cuối -> tính ra diện tích
 * sau đó dịch con trỏ thấp hơn
 *  -> dịch con trỏ cao hơn thì chiều rộng giảm, và chiều cao giữ nguyên hoặc giảm đi (vì căn cứ vào chiều cao min)
 *     nên khi dịch con trỏ cao thì chỉ có giảm diện tích
 *  -> dịch con trỏ thấp hơn thì chiều rộng giảm, nhưng có khả năng cải thiện chiều cào
 *      có khả năng tăng, bằng hoặc giảm diện tích (tối hơn phương án kia chỉ có giảm)
 *  -> tính tới khi 2 pointer gặp nhau -> max
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lptr = 0;
        int rptr = height.size() - 1;
        int ret = 0;
        while (lptr < rptr)
        {
            int temp = (rptr - lptr) * min(height[lptr], height[rptr]);
            ret = max(temp, ret);
            if(height[lptr] > height[rptr])
            {
                rptr--;
            }
            else
            {
                lptr++;
            }
        }
        return ret;
    }
};


int main()
{

}

// vertical: thẳng đứng
