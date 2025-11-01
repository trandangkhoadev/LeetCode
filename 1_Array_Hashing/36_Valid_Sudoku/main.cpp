
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * @brief Soluion đầu tiên nghĩ ra
 * Duyệt mảng 2 chiều n^2 trường hợp này là k^2 (k = 9)
 * Dùng unordered_set để lưu lại số đã xuất hiện trong row, column, block
 */
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<unordered_set<char>> checkRow{9};
//         vector<unordered_set<char>> checkColumn{9};
//         vector<unordered_set<char>> checkBlock{9};
//         for(int row = 0; row < 9; row++)
//         {
//             for(int column = 0; column < 9; column++)
//             {
//                 if(board[row][column] != '.')
//                 {
//                     //Check row
//                     if(checkRow[row].insert(board[row][column]).second != true)
//                     {
//                         return false;
//                     }

//                     // Check column
//                     if(checkColumn[column].insert(board[row][column]).second != true)
//                     {
//                         return false;
//                     }

//                     // Check block
//                     if(column < 3)
//                     {
//                         if(checkBlock[row / 3].insert(board[row][column]).second != true)
//                         {
//                             return false;
//                         }
//                     }
//                     else if(column < 6)
//                     {
//                         if(checkBlock[(row / 3) + 3].insert(board[row][column]).second != true)
//                         {
//                             return false;
//                         }
//                     }
//                     else
//                     {
//                         if(checkBlock[(row / 3) + 6].insert(board[row][column]).second != true)
//                         {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

/**
 * @brief Solution 2:
 * Vẫn duyệt 2 chiều k^2
 * Dùng mảng 9 phần tử thay vì dùng unorder_set, mỗi phần tử đại diện cho sự xuất hiện của 1 số
 * Tối ưu thuật toán tính block, cho đỡ rườm rà
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        bool checkRow[9][9] = {false};
        bool checkColumn[9][9] = {false};
        bool checkBlock[9][9] = {false};
        for(int row = 0; row < 9; row++)
        {
            for (int column = 0; column < 9; column++)
            {
                if(board[row][column] == '.')
                {
                    continue;
                }
                int value = board[row][column] - '1';
                int blockIndex = ((column / 3) * 3) + (row / 3);

                // Check if value alive in row, column or block return false
                if(checkRow[row][value] || checkColumn[column][value] || checkBlock[blockIndex][value])
                {
                    return false;
                }
                // If not add to check arrray
                checkRow[row][value] = checkColumn[column][value] = checkBlock[blockIndex][value] = true;
            }
        }
        return true;
    }
};

/**
 * @brief Solution 3: tối ưu cực đại, sử dụng bitmask
 * Hiện tại mảng bool chỉ có 2 giá trị true, false, mà lưu trữ vậy thì tốn tài nguyên
 * nên chỉ cần 1 và 0 là được
 * 
 */



int main()
{ 
    vector<vector<char>> board = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
}