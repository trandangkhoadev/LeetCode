


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fasterPtr = head;
        ListNode *lowerPtr = head;
        while(fasterPtr->next != nullptr)
        {
            fasterPtr = fasterPtr->next->next;
            lowerPtr = lowerPtr->next;
            if(fasterPtr == lowerPtr)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

}