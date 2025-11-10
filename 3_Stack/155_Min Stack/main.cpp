#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <stack>
using namespace std;

/**
 * @brief Phương pháp suy nghĩ nhanh giải bài toán
 * tạo 1 stack lưu trữ. các push, pop, top thì dùng của stack như bình thường
 * ngoài việc lưu 1 stack ta phải lưu thêm 1 sort list để truy xuất ra min nhanh chóng
 * và container luôn luôn sort mỗi khi có phần tử mới là map/set
 *  -> map/set chĩ hố trợ 1 key, nên chúng ta phải dùng multimat/set
 * tuy nhiên chúng ta chỉ cần key đại diện cho value đã push vào nên dùng multiset
 * Khi pop ra, chúng ta phải duyệt qua multiset để xóa đúng 1 phần tử đó
 * 
 * -> Cách này chạy chậm quá, vì dùng multiset, Sort nên nlogn
 */

// class MinStack {
// private:
//     stack<int> myStack;
//     multiset<int> mySet;
//     int stackSize = 0;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         myStack.push(val);
//         mySet.insert(val);
//     }
    
//     void pop() {
//         int topValue = myStack.top();
//         myStack.pop();
//         for(auto it = mySet.begin(); it != mySet.end(); it++)
//         {
//             if (*it == topValue)
//             {
//                 mySet.erase(it);
//                 break;
//             }
//         }
//     }
    
//     int top() {
//         return myStack.top();
//     }
    
//     int getMin() {
//         return *mySet.begin();
//     }
// };

/**
 * @brief Phương án tối ưu hơn
 * Idea: Vì chúng ta chỉ hỗ trợ phương thức pop (lấy từ trên xuống dưới)
 * nên sẽ không có trường hợp phải lấy phần tử ở giữa
 * -> Từ idea này chúng ta sẽ tạo 2 stack
 *      - 1 stack hỗ trợ pop, push,.. nhưng bình thường
 *      - 1 stack lưu trữ min, nếu phần tử mới push vào bé hơn hoặc bằng min, thì push vào stack
 *      phần tử lớn hơn thì không care
 *          Lý do: khi cần lấy ra phần tử đó, thì pop nó ra ở stack 1
 *                 khi nào getmin()trả về phần tử đó thì làm sao mình có mà trả về
 *                      -> không bao giờ, vì khi đó phải pop hơn các phần tử nhỏ hơn đi, nhưng mà pop
 *                         của stack thì phải theo thứ tự -> nó sẽ được pop ra trước khi nó trở thành min
 * 
 * -> Cách này beat 100% time nhưng cũng còn nhược điểm, space quá nhiều, tốn 2 stack
 * -> có thể optimise lại 1 stack
 * 
 */

// class MinStack {
// private:
//     stack<int> myStack;
//     stack<int> minStack;
// public:
//     MinStack() {
        
//     }
//     void push(int val) {
//         myStack.push(val);
//         if (!minStack.empty())
//         {
//             if(minStack.top() >= val)
//             {
//                 minStack.push(val);
//             }
//         }
//         else
//         {
//             minStack.push(val);
//         }
//     }
//     void pop() {
//         if (myStack.top() == minStack.top())
//         {
//             minStack.pop();
//         }
//         myStack.pop();
//     }
//     int top() {
//         return myStack.top();
//     }
//     int getMin() {
//         return minStack.top();
//     }
// };


/**
 * @brief Phương án dùng 1 stack
 * Idea: push vào stack value, kèm theo min tại thời điểm đó
 */

class MinStack {
private:
    stack<pair<int, int>> myStack;
    int currentMin = 0;
public:
    MinStack() {
        
    }
    void push(int val) {
        if(!myStack.empty())
        {
            currentMin =  min(currentMin, val);
        }
        else
        {
            currentMin = val;
        }
        myStack.push({val, currentMin});

    }
    void pop() {
        myStack.pop();
    }
    int top() {
        return myStack.top().first;
    }
    int getMin() {
        return myStack.top().second;
    }
};

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(0);
    minStack->push(1);
    minStack->push(0);
    std::cout << minStack->getMin() << std::endl; 
    // minStack->pop();
    // std::cout << minStack->getMin() << std::endl; 
    // minStack->pop();
    // std::cout << minStack->getMin() << std::endl; 
    // minStack->pop();
    // minStack->push(-2);
    // minStack->push(-1);
    // minStack->push(-2);
    // std::cout << minStack->getMin() << std::endl; 
    // minStack->pop();
    // minStack->top();
    // std::cout << minStack->getMin() << std::endl; 
    // minStack->pop();
    // std::cout << minStack->getMin() << std::endl; 
    // minStack->pop();
    // minStack->top();    // return 0
    // std::cout << minStack->getMin()<< std::endl; 
    // // return -2


}