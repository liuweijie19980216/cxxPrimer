/*
 * @Author: Liu Weijie
 * @Date: 2022-04-22 12:14:18
 * @LastEditTime: 2022-04-22 12:27:07
 * @FilePath: /Repository/cxxprimer/chap1/1.4.cpp
 * @Description: 练习1.4: 我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*来打印两个数的积
 *               练习1.7: 编译一个包含不正确嵌套注释的程序，观察编译器返回的错误信息
 * Copyright (c) 2022 by Liu Weijie, All Rights Reserved.
 */

#include <iostream>

int main()
{
    int a = 1, b = 2;
    /*
     * /* */
    输出语句
    * /
            std::cout
        << a << " * " << b << " = " << a * b << std::endl;
}
