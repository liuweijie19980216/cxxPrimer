/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 11:07:45
 * @LastEditTime: 2022-04-24 11:11:36
 * @FilePath: /Repository/cxxprimer/chap1/1.18.cpp
 * @Description: 编译并运行本节的程序，给它输入全部相等的值。再次运行程序，输入没有重复的值。
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>

int main()
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
                ++cnt;
            else
            {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}