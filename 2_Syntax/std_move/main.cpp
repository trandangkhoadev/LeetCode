
/**
 * @brief std::move. 
 * Nằm trong thư viện <utility>
 * Được dùng để chuyển toàn bộ địa chỉ, giá trị của 1 object sang 1 object khác
 * 
 * Trong 1 class:
 *  - Khi define 1 constructor mà truyền vào rvalue thì đó là move
 *  - Khi define 1 constructor mà truyền vào lvalue thì đó là copy        
 */

#include <utility>
#include <iostream>


class Home
{
public:
    int data1;
    int data2;
    // constructor
    Home() {}
    // destructor
    ~Home() {}
    /**
     * @brief Copy constructor
     * Với cách viết bên dưới thì với 1 data sẽ ứng với 1 dòng code, data tăng lượng code cũng tăng
     */
    Home(const Home& ins)
    {
        this->data1 = ins.data1;
        this->data2 = ins.data2;
    }
    /**
     * @brief Copy constructor để compiler tự sinh copy constructor
     * 
     */
    Home(const Home& ins) = default;
    
};


int main()
{
    int a = 10;
    int b = std::move(a);
    std::cout << b << std::endl; 
    std::cout << a << std::endl; 
}



// Vietes 