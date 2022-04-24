/*
 * @Author: Liu Weijie
 * @Date: 2022-04-22 18:44:15
 * @LastEditTime: 2022-04-22 18:46:05
 * @FilePath: /Repository/cxxprimer/chap1/1.9.cpp
 * @Description: 练习1.9: 编写程序，使用while循环将50到100的整数相加
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>

int main()
{
    int index = 50, sum = 0;

    while (index <= 100)
    {
        sum += index;
        ++index;
    }

    std::cout << "sum of 50 ~ 100 is: " << sum << std::endl;
    return 0;
}
