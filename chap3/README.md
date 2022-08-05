# 第3章 字符串、向量、数组
## 3.1 命名空间using声明

使用`using`声明无须专门的前缀就能使用所需的名字。
```c++
using namespace::name;
```

- 每个名字都需要独立的using声明，而且每句话都要以分号结束。

- 头文件不应该包含`using`声明，防止产生名字冲突。
  
## 3.2 标准库类型`string`
`string`表示可变长的字符序列。

### 3.2.1 定义和初始化`string`对象
```c++
string s1;  // 默认初始化，s1是一个空字符串
string s2; // s2是s1的副本
string s3 = "hiya";  // s3是该字符串字面值的副本
string s4(10, 'c');   // s4的内容是cccccccccc
```

使用字符串字面值初始化`string`对象时，会除了字面值最后的空字符。

**直接初始化和拷贝初始化**

使用等号是拷贝初始化，编译器把等号右侧的初始值拷贝带新创建的对象中去。不使用等号是直接初始化。

### 3.2.2 `string`对象上的操作
- os << s：将s写到输出流os当中，返回os
- is >> s：从is读取字符串赋给s，字符串以空白分隔，返回s
- getline(is, s)：从is中读取一行赋给，返回is
- s.empty()：s为空返回true
- s.size()：返回s中字符的个数
- s[n]：返回s中第n个字符的引用
- s1 + s2：返回s1和s2拼接后的结果
- s1 = s2：用s2的副本替代s1中原有的字符
- s1 == s2：二者字符完全一样，返回true
- s1 != s2：二者字符不一样，返回true
- <, <=, >, >= ：利用字符在字典中的顺序进行比较

**读写`string`对象 **

```c++
string s;
cin >> s;
cout << s;
```
**读取未知数量的`string`对象**
```c++
string word;
while(cin >> word)
    cout << word;
```

**使用`getline`读取一整行**

`getline`一遇到换行符就结束读取操作并返回结果。
```c++
string line;
while(getline(cin, line))
    cout << line << endl;
```

**`string`的`empty`和`size`操作**

`string.empty()`判断`string`是否为空，`string.size()`判断`string`中字符的个数。

**string::size_type类型**

`size`函数返回的是一个`string::size_type`类型的值。它是一个无符号类型的值，而却足够存放下任务`string`对象的大小。允许编译器通过`auto`和`decltype`来推断变量的类型。

不能混用无符号类型和有符号类型的变量，如果将`string::size_type`与一个负整数比较，永远会是负整数大，因为负值会自动转换成一个比较大的无符号值。

注意：如果表达式中已经有了`size()`函数就不要再使用`int`了。

**比较`string`对象**

比较运算符逐一比较`string`对象中的字符，并且对大小写敏感。

1. 如果较短`string`和较长`string`对应位置相同，则较短`string`小于较长`string`
2. 如果两个`string`在某些位置上不一致，那`string`对象比较的结果是第一对不同字符串比较的结果。

**为`string`类型赋值**

允许一个`string`对象赋值给另一个`string`对象。

**两个`string`对象相加**

两个`string`拼接成一个新的`string`对象。

**字面值和`string`对象相加**

必须确保加法运算符两侧的运算对象至少有一个是`string`。

字符串字面值和`string`是不同的类型。

### 3.2.3 处理`string`对象中的字符

cctype头文件中的函数
- isalnum(c)：当c时字母或数字时为真
- isalpha(c)：当c是字母时为真
- iscntrl(c)：当c是控制字符时为真
- isdigit(c)：当c是数字时为真
- isgraph(c)：当c不是空格但可打印时为真
- islower(c)：当c是小写字母时为真
- isprint(c)：当c是可打印字符时为真
- ispunct(c)：当c是标点符号时为真
- isspace(c)：当c是空格是为真
- isupper(c)：当c是大写字母时为真
- isxdigit(c)：当c是十六进制数字时为真
- tolower(c)：转换为小写字母
- toupper(c)：转换为大写字母

C++程序中应该使用cname的头文件而不是使用name.h的形式，标准库中的名字总能在命名空间std中找到。

**使用基于范围的for语句**
```c++
for(declaration: expression)
    statement
```
其中，expression部分是一个对象，用来表示一个序列。declaration部分负责定义一个变量，用来访问序列中的基础元素。
```c++
string str("some string");
for(auto c: str)
    cout << c << endl;
```

使用范围for语句和ispunct来统计`string`对象中标点符号的个数：
```c++
string str("Hello World!!!");
decltype(s.size()) punct_cnt = 0;
for(auto c: str)
    if (ispunct(c))
        ++punct_cnt;
cout << punct_cnt << endl;
```

**使用范围for语句改变字符串中的字符**

如果想要改变`string`对象中字符的值，必须报循环变量定义成引用类型。

**只处理一部分字符**

要想访问`string`对象中的单个字符有两种方式：一种是使用下标，另一种是使用迭代器。

**下标运算符**`[]`接受的参数是`string::size_type`类型的值，返回值是该位置上字符的引用。

注意事项：
- `string`对象的下标必须大于0而小于`s.size()`，否则会引发不可预知的后果
- 在访问指定字符之间，首先检查`s`是否为空，如果`s`为空，`s[0]`的结果将是未定义的。

**使用下标执行迭代**

```c++
for(decltype(s.size()) index = 0; 
    index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]);

```

上面的程序中，逻辑与运算符`&&`左侧先保证了`index`不会等于`s.size()`，随意右侧访问字符串就不可能会越界。

注意检查下标的合法性。一种简单的方法是，总是设下标的类型为`string::size_type`，这样只要缺表下标小于`s.size()`就可以了。

**使用下标执行随机访问**

可以通过下标直接访问某个字符。注意，无论何时使用字符串的下标，都是检查其合法性。
