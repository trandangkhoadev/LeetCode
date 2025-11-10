/**
 * @file main.cpp
 * @brief This file is about typedef keyword in c++
 *
 * @version 1.0
 * @date 2025-11-07
 * @author Tran Dang Khoa
 * @copyright Copyright (c) 2025 K-Project
 */

#include <iostream>
#include <vector>
#include <map>
#include <functional>

// Typedef basic
typedef unsigned long long u64;

// Typedef basic
typedef int* IntPtr;

typedef std::pair<std::string, int> StudentInfo;

struct Point
{
    int x;
    int y;
};
// Typedef for struct
typedef Point Point2D;

// Typedef for struct simplify
struct Point3
{
    int x;
    int y;
    int z;
}typedef Point3D;

void printPoint(Point2D pnt)
{
    std::cout << pnt.x << std::endl;
    std::cout << pnt.y << std::endl;  
}
void printPoint3D(Point3D pnt)
{
    std::cout << pnt.x << std::endl;
    std::cout << pnt.y << std::endl;  
    std::cout << pnt.z << std::endl;  
}

typedef int(*functionPtr)(int, int); 
int sum(int a, int b)
{
    return a + b;
}

typedef void(*callbackPtr)();
int mainFunction(void(*callback)())
{
    if (callback != nullptr)
    {
        callback();
    }
}
int mainFunction2(callbackPtr cb)
{
    if (cb != nullptr)
    {
        cb();
    }
}

//Typedef with template
template<typename T>
class MyContainer
{
public:
    T value;
};
MyContainer<int> myCon;

typedef MyContainer<int> MyCon_t;
MyCon_t myCon2;

// Typedef with complex data
typedef std::map<std::string, std::vector<std::pair<int, double>>> complexMap;

/**
 * @brief  Với tất cả các cách trên typedef có thể tạo 1 alias cho tất cả các kiểu dữ liệu
 * Tuy nhiên nếu muốn tạo typedef cho 1 kiểu dữ liệu tổng quát <T> thì typedef không làm được
 * Ví dụ muốn tạo typedef cho vector<T>, Khi ta tạo 
 *      typedef vector<T> vector_t -> lỗi
 *      chỉ có thể tạo cho từng dữ liệu cụ thế
 *      typedef vector<int> vectorInt_t -> Ok, tương tự tạo thêm với double, string,...
 * 
 * Vì vậy để tạo alias cho kiểu dữ liệu tổng quát ta cần sử dụng using
 *      template<typename T>
 *      using mVec = std::vector<T>
 *      -> Khi đó ta có thể dùng mVec<int> cho std::vector<int> ,.. và nhiều kiểu dữ liệu khác
 */
template<typename T>
using mVec = std::vector<int>;

/**
 * @brief std::function
 * là một kiểu dữ liệu có chức năng tương tự như function pointer
 * nhưng tối ưu hơn function pointer ở chỗ, nó có thể chứa lamda function, functor*
 * 
 */
std::function<int(int, int)>fSum = sum; // Hàm thông thường
std::function<int(int, int)>fLamda = [](int a, int b){return a + b;};  //Lamda
struct  Multiplier
{
    int operator()(int a, int b){return a * b;};
};
std::function<int(int, int)>fFunctor = Multiplier(); // Functor (*functor là gì tìm hiểu sau)

// Và khi áp dụng typdef vào std::function tương tự như typedef của function pointer
typedef std::function<int(int, int)> fFunc;

int main()
{
    u64 myExp = 1000000000;

    int myArray[5] = {0,1,2,3,4};
    IntPtr myPtr = &myArray[0];

    std::vector<StudentInfo> studentList;
    studentList.push_back({"Khoa", 28});
    studentList.push_back({"Tran", 29});

    int a = 10;
    int* myPre = &a;
    int (*funcPtr)(int, int);
    funcPtr = sum;
    
    std::cout << funcPtr(1, 2) << std::endl;
    functionPtr sumPtr = sum;
    std::cout << sumPtr(1,2) << std::endl; 
}

