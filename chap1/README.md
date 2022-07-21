# 第一章 开始

## 1.1 编写一个简单的C++程序

每个C++程序必须包含一个主函数main。

```c++
int main()
{
    return 0;
}
```

每个函数由四部分组成：返回类型，函数名，形参列表，函数体。

在大多数系统中，return的返回值被用来**指示状态**。返回0表示成功，非0的返回值的含义由系统定义，通常用来指出错误类型。

### 1.1.1 编译、运行程序

在UNIX系统中使用GNU编译器的命令为：

```bash
g++ -o -std=c++0x prog1 prog.cpp
# -o 表示指定可执行文件的文件名
# -std=c++0x表示支持C++11
```

如果不指定可执行文件的文件名，默认会生成a.out的可执行文件。

运行可执行文件的命令为：

```bash
./prog1
```

**1.1节练习**

**练习1.1**：查阅你使用的编译器文档，确定它所使用的文件名约定。编译并运行第2页的main程序。

在Ubuntu系统中使用GNU编译器，编译器文档以后再看。

**练习1.2**：改写程序，让它返回-1.返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

```bash
g++ -o p1-2 p1-2.cpp  # 编译程序
./p1-2  # 运行程序
echo $?  # 查看系统状态
255
```

main函数中返回值为-1，系统实际返回的值为255。系统好像以补码的形式处理函数的返回值。

## 1.2 初识输入输出

C++语言没有定义任何输入输出（IO）语句，而是通过**iostream**库来提供IO机制。iostream定义了两个基础类型**istream**和**ostream**，分别表示输入流和输出流。

**标准输入输出对象**

标准库定义了4个IO对象。

- 标准输入cin
- 标准输出cout
- 标准错误cerr, clog（clog用来输出程序的一般性输出）。

- 向流写入数据。输出运算符 `<<` ，接受两个运算对象，左侧运算对象必须是一个 `ostream` 对象，右侧运算对象是要打印的值。输出运算符的计算结果就是其左侧运算对象。
- 从流读取数据。输入运算符 `>>` ，左侧运算对象必须是一个 `istream` 对象。

**1.2节练习**
**练习1.3**：编写程序，在标准输出上打印Hello, World。

```c++
#include <iostream>

int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

**练习1.4**：我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符*，来打印两个数的积。

```c++
#include <iostream>

int main()
{
    int a, b, sum;
    std::cout << "Enter two number: " << std::endl;
    std::cin >> a >> b;
    sum = a * b;
    std::cout << a << " * " << b << " = " << sum << std::endl;
    return 0;
}
```

**练习1.5**：我们将所有输出操作放在一条很长的语句中。重写程序，将每个运算对象的打印操作放在一条独立的语句中。

```c++
#include <iostream>

int main()
{
    int a, b, sum;
    std::cout << "Enter two number: " << std::endl;
    std::cin >> a >> b;
    sum = a * b;
    std::cout << a;
    std::cout << " * ";
    std::cout << b;
    std::cout << " = ";
    std::cout << sum;
    std::cout << std::endl;
    return 0;
}
```

**练习1.6**：解释下面程序片断是否合法。

```c++
std::cout << "The sum of " << v1;
          << "and " << v2;
          << " is " << v1 + v2 << std::endl;
```

如果程序是合法的，它输出什么？如果程序不合法，原因何在？应该如何修正。

不合法。第一行程序以封号结尾，表示该语句结束。
第二行开头是一个输出运算符 `<<` ，左侧必须一个 `ostream` 对象。第三行同理。
正确的写法是：

```c++
std::cout << "The sum of " << v1;
std::cout << "and " << v2;
std::cout << " is " << v1 + v2 << std::endl;
```

## 1.3 注释简介

C++支持两种注释：

- 单行注释：//
- 多行注释：/*        */

**注意**：多行注释不能嵌套

## 1.4 控制流

### 1.4.1 while语句

**while语句**反复执行一段代码，直到给定条件为假为止。

### 1.4.2 for语句

简化循环体中递增递减的模式。

### 1.4.3 读取数量不定的输入数据

当使用一个 `istream` 对象作为条件时，其效果是为了检测流的状态。当遇到文件结束符或者无效输入时，条件会变为假。

```c++
int value, sum;
while(std::cin >> value)
    sum += value;
```

### 1.4.4 if语句

C++使用 `=` 进行赋值，用 `==` 作为相等运算符，编码过程中不能用混。

## 1.5 类简介

在C++中，我们通过定义一个类来定义自己的数据结构。一个类定义了一个类型，以及与其关联的一组操作。

### 1.5.1 Sales_item类

Sales_item类的作用是表示一本书的总销售额、售出册数和平均售价。

- 读写Sales_item。可以从标准输入读入数据，存入一个Sale_item对象中。
- Sales_item对象的加法。

**文件重定向：**

程序可以通过标准输入输出向文件中读取以及输出流。例如：

```bash
addItems <infile> outfile
```

**1.5.1节练习**

**练习1.20**：读取一组书籍销售记录，将每条记录打印到标准输出上。

```c++
#include <iostream>
#include <vector>
#include "Sales_item.h"

int main()
{
    Sales_item item;
    std::vector<Sales_item> items;
    while(std::cin >> item) {
        items.push_back(item);
    }
    for(int i = 0; i < items.size(); ++i) {
        std::cout << items[i] << std::endl;
    }
    return 0;
}
```

**练习1.21**：编写程序，读取两个ISBN相同的Sale_item对象，输出它们的和。

```c++
#include <iostream>
#include <vector>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    return 0;
}
```

**练习1.22**：编写程序，读取多个具有相同ISBN的销售纪录，输出所有记录的和。

```c++
#include <iostream>
#include <vector>
#include "Sales_item.h"

int main()
{
    Sales_item item, item_sum;
    std::vector<Sales_item> items;
    while(std::cin >> item) {
        items.push_back(item);
    }
    for(int i = 0; i < items.size(); ++i) {
        item_sum += items[i];
    }
    std::cout << item_sum << std::endl;
    return 0;
}
```

### 1.5.2 初始成员函数

**成员函数**是定义为类的一部分的函数，有时也被称为**方法**。

**1.5.2节练习**

**练习1.23**：编写程序，读取多条销售记录，并统计每个ISBN有几条销售记录。

```c++
#include <iostream>
#include <vector>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2, item_sum;
    std::cin >> item1;
    item_sum += item1;
    while(std::cin >> item2) {
        if(item2.isbn() == item1.isbn())
            item_sum += item2;
        else {
            std::cout << item_sum << std::endl;
            item1 = item2;
        }
    }
    return 0;
}
```

