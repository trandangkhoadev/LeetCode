#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;



// Bài toán này có 1 câu hỏi đầu tiên là khi 2 xe fleet rồi thì xe thứ 3 muốn fleet là chỉ cần gắn vào
// xe 2 là được phải không -> chắc là vậy 

// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

/**
 * @brief Solution quick thinking
 * Duyệt từ xe đi chậm nhất
 *  -> tìm xe phía sau xe đó, 
 *      nếu không có, xe đó là 1 fleet
 *      nếu có, duyệt qua từ xe gần nhất xem có kịp không
 *          -> Kịp thì thành fleet
 *          -> Không thì bỏ qua xe này
 * Duyệt tiếp xe chậm nhì, làm tương tự đến khi hết
 * -> On^3 duyệt khá là nhiều
 */

/**
 * @brief Solution hay hơn
 * tất cả các xe phía sau, sẽ không bao giờ qua mặt được xe đầu
 * xe thứ 3 cũng k qua mặt được xe thứ 2,...
 * duyệt xe thứ 1 xem xe thứ 2 có kịp k
 *  -> không kịp thì xe thứ 1 là 1 fleet
 * duyệt xe thứ 2 xem xe thứ 3 có kịp k ...
 *  điều kiện để đuổi kịp 
 *  distance < v phải <= distance/v của xe cần đuổi
 * 
 * Cách này tương tự như stack, nếu chúng ta push xe thứ 1 vào trong stack
 * và nếu thì thứ 2 đuổi kịp thì pop xe thứ 1 ra, push xe thứ 2 vào
 * 
 * -> kết quả cuối cùng là số lượng phần tử của stack
 */


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int noCar = position.size();
        if (noCar < 2)
        {
            return noCar;
        }
        vector<std::pair<int, int>> positionSpeed;
        for(int i = 0; i < noCar; i++)
        {
            positionSpeed.push_back(std::pair(position[i], speed[i]));

        }
        std::sort(positionSpeed.begin(), positionSpeed.end(), 
                    [](auto &a, auto&b)
                    {
                        return a.first > b.first;
                    });
        float lastTime = 0;
        int noFleet = 0;
        for(auto& ins: positionSpeed)
        {
            // std::cout << "check: "<< ins.first << " " << ins.second << std::endl; 
            float currentTime = (float)(target - ins.first)/ (float)ins.second;
            if (currentTime > lastTime)
            {
                // std::cout << "Time: "<< currentTime << std::endl; 
                noFleet++;
                lastTime = currentTime;
            }
        }
        return noFleet;
    }
};

int main()
{
    int target = 12;
    vector<int> pos = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    Solution s1;
    s1.carFleet(target, pos, speed);
}