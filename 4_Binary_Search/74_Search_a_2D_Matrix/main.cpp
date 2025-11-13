#include <vector>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

/**
 * @brief Quick solution
 * Duyệt qua row ở giữa, nếu target thuộc trong khoảng dó thì check tiếp
 * Nếu nhỏ hơn thì duyệt row ở giữa của phần nhỏ hơn
 * Lớn hơn thì duyệt row ở giữa của phần lớn hơn
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix[0].size();
        int columnSize = matrix.size();

        int maxRowIndex = rowSize - 1;
        int rowl = 0;
        int rowr = columnSize - 1;

        while(rowl <= rowr)
        {
            int rowMid = rowl + (rowr - rowl) / 2;
            // std::cout << "Check row: "<< rowMid << std::endl; 
            if (matrix[rowMid][0] > target)
            {
                rowr = rowMid - 1;
                continue;
            }
            else if (matrix[rowMid][maxRowIndex] < target)
            {
                rowl = rowMid + 1;
                continue;
            }
            else
            {
                int l = 0;
                int r = maxRowIndex;
                while (l <= r)
                {
                    int mid = l + (r - l)/2;
                    int midValue = matrix[rowMid][mid];
                    // std::cout << "Check value: "<< midValue << std::endl; 
                    // std::cout << "Check targer: "<< target << std::endl; 
                    if(midValue == target)
                    {
                        return true;
                    }
                    else if(midValue > target)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                break;
                
            }
            // std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    Solution s1;
    s1.searchMatrix(matrix, 13);
}