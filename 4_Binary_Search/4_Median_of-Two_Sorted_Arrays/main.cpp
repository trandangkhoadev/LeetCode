
#include <vector>
#include<iostream>
using namespace std;

/**
 * @brief 
 * dùng merge sort
 * duyệt qua 2 mảng từ đầu đến cuối
 * mảng nào có phần tử nhỏ hơn thì sắp vào và tăng lên 1
 * chỉ cấn sắp tới index = max A + MaxB + 1 / 2 là được
 * 1 1 1 2 2 3
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sizeNum1 = nums1.size();
        int sizeNum2 = nums2.size(); 
        if(sizeNum1 + sizeNum2 < 2)
        {
            if(sizeNum1 > 0)
            {
                return (double)nums1[0];
            }
            else if (sizeNum2 > 0)
            {
                return (double)nums2[0];
            }
        }
        int midIndex = (sizeNum1 + sizeNum2) / 2;
        int i = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> mergeVector;
        double ret;
        while(i <= midIndex)
        {
            if(ptr1 > sizeNum1 - 1)
            {
                mergeVector.push_back(nums2[ptr2]);
                ptr2++;
                i++;
                continue;
            }
            if(ptr2 > sizeNum2 - 1)
            {
                mergeVector.push_back(nums1[ptr1]);
                ptr1++;
                i++;
                continue;
            }
            
            if(nums1[ptr1] < nums2[ptr2])
            {
                mergeVector.push_back(nums1[ptr1]);
                ptr1++;
                i++;
            }
            else if(nums1[ptr1] == nums2[ptr2])
            {
                mergeVector.push_back(nums1[ptr1]);
                mergeVector.push_back(nums2[ptr2]);
                ptr1++;
                ptr2++;
                i += 2;
            }
            else
            {   
                mergeVector.push_back(nums2[ptr2]);
                ptr2++;
                i++;
            }
        } 
        if(((sizeNum1 + sizeNum2) % 2) == 0)
        {
            ret = ((double)mergeVector[midIndex] + (double)mergeVector[midIndex -1]) / 2;

        }    
        else
        {
            ret = mergeVector[midIndex];
        }   
        return ret;  
    }
};

int main()
{
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {6,7,8,9,10,11,12,13,14,15,16,17};
    Solution s1;
    s1.findMedianSortedArrays(nums1, nums2);
}