

/**
 * @brief Constructor (mở rộng ra operator: dưới đây là 6 hàm tự động được sinh ra khi tạo 1 class, nếu không define)
 * 
 * constructor: hàm tạo
 * destructor: hàm hủy
 * 
 * copy constructor: hàm sao chép. Tạo 1 đối tượng từ đối tượng khác Home b = a; hoặc Home b(a);
 * copy assignment operator: hàm sao chếp. khi đối tượng đã tồn tại được gán lại từ đối tượng khác b = a;
 *      -> học về operator để hiểu hơn về phần này. Chỗ này định nghĩa phép toán gán = trong class (rvalue)
 * 
 * move constructor: hàm chuyển. Tạo một đối tượng từ đối tượng khác Home b = std::move(a);
 * move assignment operator: hàm chuyển. Khi đối tượng đã tồn tại được gán bằng đối tượng khác b = std::move(a);
 *      -> cũng là định nghĩa phép toán gán = trong class (lvalue)
 * 
 */

#include <iostream>


class Home
{
    Home() = default;
    ~Home() = default;
    Home(const Home& ins) = default;
    Home& operator=(const Home& ins) = default;
    Home(Home&& ins) = default;
    Home& operator=(Home&& ins) = default;
};
int main ()
{
}
