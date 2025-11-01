#include <iostream>

using namespace std;

/**
 * @brief Phương pháp đơn giản nhất
 * Biến chuôi thành normal, xóa bỏ ký tự, khoảng trắng,.. , biến chữ hoa thành chữ thường
 * so sánh các ký tự đối xứng
 * 
 * Nhược điểm, phải tạo thêm 1 mảng
 */
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string normalStr;
//         for(char c:s)
//         {
//             if(std::isalnum(c))
//             {
//                 normalStr += std::tolower(c);
//             }
//         }
//         int length = normalStr.size();
//         for(int i = 0; i < length / 2 ; i++)
//         {
//             if (normalStr[i] != normalStr[length - i -1])
//             {
//                 return false;
//             }
//         }
//     }
// };

/**
 * @brief Phương án tối ưu hơn
 * Đặt 2 con trỏ ở đầu và cuối, duyệt lại gần nhau
 * Gặp ký tự đặt biệt, khoảng trắng,.. thì tự động dịch tiếp
 * sau đó so sánh 2 ký tự đã lowcase.
 * 
 * dừng lại khi 2 con trỏ gặp nhau, phương án này lỗi coding 1 chút vè điều kiện lIndex < rIndex
 * được kiểm tra quá nhiều lần, thật ra chỉ cần 1 lần ở while đầu là đủ
 */
// class Solution
// {
// public:
//     bool isPalindrome(string s) {
//         int lIndex = 0;
//         int rIndex = s.size() - 1;
//         while (lIndex < rIndex)
//         {
//             while((!std::isalnum(s[lIndex])) && (lIndex < rIndex))
//             {
//                 lIndex++;
//             }
//             while((!std::isalnum(s[rIndex])) && (lIndex < rIndex))
//             {
//                 rIndex--;
//             }
//             if(std::tolower(s[lIndex]) != std::tolower(s[rIndex]))
//             {
//                 return false;
//             }
//             lIndex++;
//             rIndex--;
//         }
//         return true;
//     }
// };

/**
 * @brief Phương án tối ưu nhất
 * 
 */
class Solution
{
public:
    bool isPalindrome(string s) {
        int lIndex = 0;
        int rIndex = s.size() -1;
        while(lIndex < rIndex)
        {
            if(!std::isalnum(s[lIndex]))
            {
                lIndex++;
            }
            else if(!std::isalnum(s[rIndex]))
            {
                rIndex--;
            }
            else if(std::tolower(s[lIndex]) != std::tolower(s[lIndex]))
            {
                return false;
            }
            else
            {
                lIndex++;
                rIndex--;
            }
        }
    }
};


int main()
{
    string s ="A man, a plan, a canal: Panama";
    Solution s1;
    s1.isPalindrome(s);
}
