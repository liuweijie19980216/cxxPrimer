/*
 * @Author       : Weijie Liu
 * @Date         : 2022-07-21 22:37:28
 * @LastEditTime : 2022-07-21 23:41:22
 * @Description  : p1.5
 */
#include <iostream>

int main()
{
    int a, b, sum;
    std::cout << "Enter two number: " << std::endl;
    std::cin >> a >> b;
    sum = a * b;
    std::cout << a;
    std::cout << " * ";
    std::cout << b;
    std::cout << " = ";
    std::cout << sum;
    std::cout << std::endl;
    return 0;
}