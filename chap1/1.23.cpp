/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 11:51:48
 * @LastEditTime: 2022-04-24 14:09:34
 * @FilePath: /Repository/cxxprimer/chap1/1.23.cpp
 * @Description: 编写程序，读取多条销售记录，并统计每个ISBN有几条销售记录。
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, item;
    int cnt = 0;
    std::cout << "please input multi book information: " << std::endl;
    if (std::cin >> currItem)
    {
        cnt = 1;
        while (std::cin >> item)
        {
            if (item.isbn() == currItem.isbn())
            {
                cnt += 1;
            }
            else
            {
                std::cout << "The book of the " << currItem.isbn() << " occur " << cnt << " times" << std::endl;
                currItem = item;
                cnt = 1;
            }
        }
        std::cout << "The book of the " << currItem.isbn() << " occur " << cnt << " times" << std::endl;
    }
    return 0;
}
