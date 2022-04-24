/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 11:37:32
 * @LastEditTime: 2022-04-24 11:39:40
 * @FilePath: /Repository/cxxprimer/chap1/1.22.cpp
 * @Description: 编写程序，读取多个ISBN相同的Sales_item记录，输出它们的和
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item, itemSum;
    std::cout << "please input multi book information: " << std::endl;
    while (std::cin >> item)
    {
        itemSum += item;
    }

    std::cout << itemSum << std::endl;
    return 0;
}
