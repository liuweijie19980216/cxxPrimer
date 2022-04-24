/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 10:17:29
 * @LastEditTime: 2022-04-24 10:50:10
 * @FilePath: /Repository/cxxprimer/chap1/1.13.cpp
 * @Description: 使用for循环重做1.4.1节中的所有练习
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>

int main()
{
    // 1.9
    int sum = 0;
    for (int i = 0; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << "1.9: sum of 50 ~ 100 is: " << sum << std::endl;

    // 1.10
    std::cout << "1.10" << std::endl;
    for (int i = 10; i >= 0; --i)
    {
        std::cout << i << std::endl;
    }

    // 1.11
    std::cout << "please input two number: " << std::endl;
    int begin = 0, end = 0;
    std::cin >> begin >> end;
    std::cout << "1.11" << std::endl;
    for (int i = begin; i <= end; ++i)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
