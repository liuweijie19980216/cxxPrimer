/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 11:23:31
 * @LastEditTime: 2022-04-24 11:33:12
 * @FilePath: /Repository/cxxprimer/chap1/1.20.cpp
 * @Description: 编写一个程序，读取一组书籍的销售记录，并将每条记录打印到标准输出上。
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    std::cout << "please input book information: " << std::endl;
    std::cin >> item;
    std::cout << item << std::endl;
    return 0;
}
