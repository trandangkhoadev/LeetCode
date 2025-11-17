#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @brief Quick thinking solution
 * so sánh 2 node đầu tiên, node nào nhỏ hơn thì bóc ra, rồi tìm node tiếp theo
 * 
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while((list1 != nullptr) && (list2 != nullptr))
        {
            if(list1->val <= list2 ->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1 == nullptr)
        {
            cur->next = list2;
        }
        else if(list2 == nullptr)
        {
            cur->next = list1;
        }

        return dummy.next;
    }
};




int main()
{
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution s1;
    s1.mergeTwoLists(list1, list2);
}