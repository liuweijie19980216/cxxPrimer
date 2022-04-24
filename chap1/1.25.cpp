/*
 * @Author: Liu Weijie
 * @Date: 2022-04-24 14:13:32
 * @LastEditTime: 2022-04-24 14:15:59
 * @FilePath: /Repository/cxxprimer/chap1/1.25.cpp
 * @Description: 编译并运行本节书中给出的书店程序
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;
    if (std::cin >> total)
    {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "no data?!" << std::endl;
        return -1;
    }
    return 0;
}
