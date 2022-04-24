/*
 * @Author: Liu Weijie
 * @Date: 2022-04-22 18:46:22
 * @LastEditTime: 2022-04-22 18:49:36
 * @FilePath: /Repository/cxxprimer/chap1/1.10.cpp
 * @Description: 练习1.10: 除了++运算符将运算对象的值增加1之外，还有一个递减运算符--实现将值减少1。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */
#include <iostream>

int main()
{
    int val = 10;

    while (val >= 0)
    {
        std::cout << val << std::endl;
        --val;
    }

    return 0;
}
