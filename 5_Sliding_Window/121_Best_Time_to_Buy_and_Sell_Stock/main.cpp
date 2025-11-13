#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lPtr = 0;
        int rPtr = 0;
        int size = prices.size();
        if (size < 2)
        {
            return 0;
        }
        int maxValue = 0;
        while (rPtr < size)
        {
            if(prices[rPtr] < prices[lPtr])
            {
                lPtr = rPtr;
            }
            else
            {
                maxValue = max(prices[rPtr] - prices[lPtr], maxValue);
            }
            rPtr++;
        }
        return maxValue;
    }
};
int main()
{

}