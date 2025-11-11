#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * @brief Solution check nhanh
 * với từng phần tử, duyệt qua các phần tử còn lại tìm ngày nóng hơn -> n^2
 * -> cách này suy nghĩ thôi không cần code, vì quá đơn giản
 */

/**
 * @brief Solution tối ưu hơn
 * tạo 1 stack lưu trữ index, và sắp xếp từ ngày nóng tới ngày lạnh
 * Duyệt từ cuối đến đầu. So sánh với từng phần tử trong stack
 *  - nếu tới vị trí nóng hơn vị trí đang set -> tính được kết quả. Sau đó pop vị trí nhỏ hơn ra, và thay bằng vị trí hiện tại (vì khi xét các ngày trước đó nữa, nếu ngày hiện tại nóng hơn thì return được r, còn nếu ngày hiện tại lạnh hơn, thì mấy ngày lạnh hơn ngày hiện tại không còn value) 
 *  - nếu cả stack không có vị trí nóng hơn -> tính được kết quả 0. Sau đó push vị trí hiện tại vào
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> tempIndex;
        int size = temperatures.size();
        vector<int> ret(size, 0);
        for(int i = size - 1; i >= 0; i--)
        {
            while (tempIndex.size() > 0 )
            {
                if(temperatures[tempIndex.top()] > temperatures[i])
                {
                    ret[i] = tempIndex.top() - i;
                    tempIndex.push(i);
                    break;
                }
                else
                {
                    tempIndex.pop();
                }
            }
            if (tempIndex.size() == 0)
            {
                ret[i] = 0;
                tempIndex.push(i);
            }
        }
        return ret;
    }
};
int main()
{                   
    vector<int> temp = {73,74,75,71,69,72,76,73};
    Solution s1;
    vector<int> ret = s1.dailyTemperatures(temp);

    // vector<int>myVect(3, 0);
    // myVect[0] = 1;
    // myVect[1] = 2;
    // myVect[2] = 3;
    // for(auto& ins: myVect)
    // {
    //     std::cout << ins << std::endl; 
    // }
    return 0; 

}

