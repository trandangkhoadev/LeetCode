
/**
 * @brief rvalue lvalue
 * lvalue: là biểu thức có địa chỉ cụ thể trong bộ nhớ, có thể lấy được địa chỉ của nó (& được)
 * rvalue: là giá trị tạm thời, không có địa chỉ cụ thể
 * 
 * reference:
 * - Kiểu                   - cú pháp       - Có thể bind với       - Ghi chú
 * - lvalue reference       - T&            - lvalue                - truyền tham chiếu thông thường
 * - rvalue reference       - T&&           - rvalue                - Dành cho move semantics. 
 * 
 * Move sematics (std::move(x) biến đổi 1 lvalue thành 1 rvalue)
 * ví dụ 
 * int x = 10;
 * int y = x; (khi này sẽ y sẽ copy dữ liệu của x và chép vào địa chỉ của mình -> tốn tài nguyên)
 * int y = std::move(x) (chuyển toàn bộ địa chỉ, giá trị của x sang y -> không tốn tài nguyên, tuy nhiên x lúc này rỗng)
 * 
 * Template
 * T&: luôn là lvalue reference (tiếng việt là reference của 1 lvalue)
 * template<typename T> 
 * void onlyLvalue(T& x) { cout << "Lvalue only\n"; }
 * 
 * T&&: 
 * template<typename T>
 * void bothValue(T&& x) { cout << "Both lvalue & rvalue\n"; }
 */


#include <iostream> 
int foo(int& value)
{
    std::cout << value << std::endl;
    value = 2;
    std::cout << value << std::endl; 
}


int main()
{
    int x = 10;
    foo(x);
    std::cout << x << std::endl; 
}