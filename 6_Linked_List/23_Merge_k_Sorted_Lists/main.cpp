#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* cur = &dummy;
        int size = lists.size();
        while(true)
        {
            int minValue = INT_MAX;
            int minIndex = -1;
            for(int i = 0; i < size; i++)
            {
                if(lists[i] != nullptr && lists[i]->val < minValue)
                {
                    minValue = lists[i]->val;
                    minIndex = i;
                }
            }
            if(minIndex == -1)
            {
                break;
            }

            cur->next = lists[minIndex];
            lists[minIndex] = lists[minIndex]->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};