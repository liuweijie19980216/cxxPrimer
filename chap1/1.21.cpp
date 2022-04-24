/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 11:23:31
 * @LastEditTime: 2022-04-24 11:36:33
 * @FilePath: /Repository/cxxprimer/chap1/1.21.cpp
 * @Description: 编写一个程序，读取两个ISBN相同的Sales_item对象，输出它们的和
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cout << "please input two book information: " << std::endl;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    return 0;
}
