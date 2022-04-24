/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 10:57:38
 * @LastEditTime: 2022-04-24 10:59:55
 * @FilePath: /Repository/cxxprimer/chap1/1.16.cpp
 * @Description: 编写程序，从cin读取一组数，输出其和
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>

int main()
{
    int value = 0, sum = 0;
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "sum: " << sum << std::endl;
}
