/*
 * @Author: Liu Weijie
 * @Date: 2022-04-22 18:46:22
 * @LastEditTime: 2022-04-22 18:47:10
 * @FilePath: /Repository/cxxprimer/chap1/1.11.cpp
 * @Description: 练习1.11: 编写程序，提示用户输入两个整数，打印这两个整数所指定范围内所有整数
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>

int main()
{
    std::cout << "Enter tow interger: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1 > v2)
    {
        std::cout << "The range of " << v2 << " to " << v1 << std::endl;
        while (v2 <= v1)
        {
            std::cout << v2 << std::endl;
            ++v2;
        }
    }
    else
    {
        std::cout << "The range of " << v1 << " to " << v2 << std::endl;
        while (v1 <= v2)
        {
            std::cout << v1 << std::endl;
            ++v1;
        }
    }
    return 0;
}
