#include <iostream>
#include <vector>
class Solution
{
public:
/**
 * @brief bubbleSort
 * Algorithm so sánh 2 số liền kề và đưa số lớn hơn ra phía sau
 * lặp lại 1 vòng thì số lớn nhất sẽ đứng cuối
 * lặp lại n * (n-1) vòng thì sẽ sắp xếp theo thứ tự O(n)
 */
    std::vector<int>bubbleSort (std::vector<int> &array){}
/**
 * @brief inserSort
 * Sắp xếp chèn, tách mảng ra làm 2 phần, phần chưa sắp xếp và đã sắp xếp
 * duyệt từng phần tử bên mảng chưa sắp xếp, và chèn vào vị trí đúng trong mảng đã sắp xếp
 * sắp xếp chèn mỗi phần tử cần On, và cả mảng cần n *n O(n)
 */
    std::vector<int>insertSort (std::vector<int> &array){}
/**
 * @brief selectionSort
 * Sắp xếp chọn, đưa phần tử nhỏ nhất ra đầu mảng và lặp lại
 * Duyệt qua cả mảng và tìm phần tử nhỏ nhất đưa đến đầu On
 * lặp lại thêm n lần O(n)
 */
    std::vector<int> slectionSort (std::vector<int> &array) {}

/***************************** Các thuật toán chia để trị *****************************************************/
/**
 * @brief mergeSort
 * Sắp xếp trộn, chia mảng lớn thành các mảng con, cho đến khi mảng con còn 1 phần tử
 * merge 2 mảng con với nhau. Thuật toán merge:
 * tạo 1 mảng tạm size bằng tổng 2 mảng, so sánh 2 phần tử đầu tiền của 2 mảng, phần tử nào nhỏ hơn sẽ add vào biến tạm
 * tiếp tục xét đến phần tử tiếp theo của mảng vừa lấy giá trị ra, và so sánh
 */
    std::vector<int> mergeSort (std::vector<int> &array) {}
/**
 * @brief quickSort
 * Chọn 1 giá trị trong mảng (pivot), sắp xếp mảng thành 2 mảng con, mảng bên trái nhỏ hơn pivot, mảng bên phải lớn hơn pivot
 * đệ qua cho các mảng con, cho đến khi mảng con còn 1 hoặc 0 phần từ thì dừng lại
 * 
 * Thuật toán để sắp 2 mảng con bên trái và bên phải: kỹ thuật partition
 * Chọn pivot là phần tử cuối cùng
 * đặt 2 biến i đại diện mảng bên trái, j đại diện mảng bên phải. i = -1, j = 0
 * so sánh j với pilot, nếu j > pilot j tăng lên 1.
 * so sánh i với pilit nếu i <= pilot i tăng lên 1, đổi giá trị tại i và j cho nhau
 * đều này sẽ đảm bảo phần tử nhỏ hơn sẽ chuyển về bên trái, phần tử lớn hớn sẽ dời về bên phải
 */
    std::vector<int> quickSort (std::vector<int> &array) {}


/***************************** Các thuật toán nâng cao *****************************************************/

/**
 * @brief heapSort
 * Thuật toán sử dụng cây nhị phân (mỗi node có tối đa 2 node con)
 * đưa mảng ban đầu vào 1 cây nhị phân, đưa vào node cha trước node con sau, từ trái sang phải
 * Sau đó thực hiện heapify: thuật toán để đưa giá trị nhỏ nhất(max heap) or min heap về gốc sau đó lấy phần tử đó vào mảng
 * lặp lại sẽ sắp xếp được mảng
 * 
 */
};


int main()
{
    std::cout << "" << std::endl;
}
