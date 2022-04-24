/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 11:12:50
 * @LastEditTime: 2022-04-24 11:30:20
 * @FilePath: /Repository/cxxprimer/chap1/1.19.cpp
 * @Description: 修改你为1.4.1节练习1.11所编写的程序（打印一个范围内的数），使其能处理用户输入第一个数比第二个数小的情况
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
