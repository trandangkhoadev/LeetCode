#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
/**
 * @brief topKFrequent O(n)
 * Sử dụng một map để lưu giá trị kèm cố lần xuất hiện
 * sử dụng map để sắp xếp số lần xuất hiện
 * lấy ra phần tử từ map O
 */
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector<int> ret;
    //     unordered_map<int, int> frequenceMap;
    //     map<int, int, std::greater<int>> myMap;
    //     for(int &i : nums)
    //     {
    //         frequenceMap[i]+= 1;
    //     }
    //     for(auto &it: frequenceMap)
    //     {
    //         pair<int, int>value(it.second, it.first);
    //         myMap.insert(value);
    //     }
    //     int count = 0;
    //     for(auto & it : myMap)
    //     {
    //         std::cout << it.first << " " << it.second << std::endl; 
    //         if (++count> k)
    //         {
    //             break;
    //         }
    //         ret.push_back(it.second);
    //     }
    //     return ret;
    // }


/**
 * @brief topKFrequent O(n)
 * Tạo 1 mảng kích thước bằng số phần tử của mảng ban đầu, với index là số lần suất hiện và value là instance
 * Mảng này, mỗi phần tử là 1 list, vì có khả năng nhiều instace(số) xuất hiện cùng số lần
 * Sau khi có mảng tần số xuất hiện tại thì pull ra để return
 * 
 */
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int size = nums.size();
        int count = 0;
        vector<vector<int>> array(size + 1);
        unordered_map<int, int> freqMap;
        vector<int> ret;
        for(auto& it : nums)
        {
            freqMap[it]++;
        }
        for(auto& ins : freqMap)
        {
            array[ins.second].push_back(ins.first);
        }
        for(int i = 0; i <= size; i++)
        {
            if (count < k)
            {
                if(array[size -i].size() > 0)
                {
                    count += array[size -i].size();
                    ret.insert(ret.end(), array[size -i].begin(), array[size -i].end());
                }
            }
            else
            {
                return ret;
            }
        }
    }
/**
 * @brief Còn 1 các giải nlogn nữa, sẽ được giải ở heap, priority queue
 * 
 */


};

int main()
{
    vector<int>nums = {1,1,1,2,2,3};
    Solution s1;
    vector<int> ret = s1.topKFrequent(nums, 2);
    for(auto &it: ret)
    {
        cout << it << endl;
    }
}