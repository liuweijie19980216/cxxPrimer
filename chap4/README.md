# 第4章 表达式
表达式由一个或多个**运算对象**组成，对表达式求值将得到一个**结果**。字面值和变量是最简单的表达式，其结果就是字面值和变量的值。

## 4.1 基础
### 4.1.1 基本概念
作用于一个运算对象的运算符是一元运算符，作用于两个运算对象的运算符是二元运算符，作用于三个运算对象的是三元运算符。函数调用是一种特别的运算符，对运算对象的数量没有限制。

**组合运算符和运算对象**

要想理解复杂表达式的含义，首先要理解运算符的优先级、结合律以及运算对象的求值顺序。

**运算对象转换**

在表达式的求值过程中，运算对象尝尝由一种类型转换成另一种类型。让人意外的是，小整数类型(bool, char, short)会转换成大整数类型(int)。

**重载运算符**

当运算符作用于类类型的运算对象时，用户可以自定义其含义，这种被称为重载运算符。

重载运算符的运算对象和返回值类型是由运算符定义的，但是优先级和结合律是无法改变的。

**左值和右值**

C++的表达式要么是右值，要么是左值，左值可以位于赋值语句的左侧，右侧则不能。

当一个对象被用作右值的时候，用的是对象的值；当对象被用作左值的时候，用的是对象的身份。

- 赋值运算符需要一个非常量的左值作为其左侧运算对象，得到的结果仍然是一个左值
- 取地址符作用于一个左值运算对象，返回的指针是一个右值
- 下标运算符的求值结果是左值

decltype作用于表达式的求值结果是左值，则得到一个引用类型。

### 4.1.2 优先级和结合律
复合表达式是指含有两个或多个运算符的表达式。

**括号无视优先级和结合律**

### 4.1.3 求值顺序

优先级规定了运算对象的组合方式，但是没有说明运算对象按照什么顺序求值。

```c++
int i = f1() * f2();
```
我们无法确定上面的程序是f1先被调用还是f2先被调用。

对于那些没有执行执行顺序的运算符来说，如果表达式指向并修改了同一个对象，将会引发错误并产生为定义的行为。
```c++
int i = 0;
cout << i << " " << ++i << endl;  // 未定义的
```

编译器无法确定是先计算i还是++i，因此表达式的行为是不可预知的。

有4中运算符明确规定了运算对象的求值顺序：
- 逻辑与运算符(&&)，它规定了先求左侧运算对象的值，只有当左侧为真时才会求右侧对象的值
- 逻辑或运算符(||)
- 条件运算符(?:)
- 逗号运算符(,)

**求值顺序、优先级、结合律**
运算对象的求值顺序与优先级和结合律无关。如果一个表达式中的多个函数影响同一对象，它是一条错误的表达式，将产生未定义的行为。

以下两条经验准则对书写复合表达式有益：

1. 拿不准的时候最好用括号来强制让表达式的组合关系符合程序逻辑的要求。
2. 如果改变了某个运算对象的值，在表达式的其他地方不要使用这个运算对象。当改变运算对象的子表达式本身就是另外一个子表达式的运算对象是该规则无效。

## 4.2 算术运算符

一元运算符的优先级最高，接下来是乘法和除法，优先级最低的是加法和减法。

算术运算符的运算对象和求值结果都是右值。

取余运算要求运算对象都是整数，而且除了m % n结果是0的情况外，结果的符号与m相同。

## 4.3 逻辑和关系运算符

关系运算符作用于算术类型或指针类型，逻辑运算符作用于任意能转换成布尔类型的类型。运算对象和求值结果都是右值。

**逻辑与和逻辑或运算符**

当且仅当左侧运算对象无法确定表达式的结果是才会计算右侧运算对象的值。这种策略被称为**短路求值**。
- 对于逻辑与运算符来说，当且仅当左侧运算对象为真时才对右侧运算对象求值
- 对于逻辑或运算符来说，当且仅当左侧运算法为假时才对右侧运算对象求值

短路求值可以确保右侧对象求值过程的正确性和安全性，在使用索引的时候可以通过左侧的运算对象避免索引的越界。

**逻辑非运算符**

逻辑非运算符(!)将运算对象的值取反后返回。

**关系运算符**

关系运算符比较运算对象的大小关系并返回布尔值，关系运算符都满足左结合律。

因为关系运算符的求值结果是布尔值，所以将几个关系运算符连写在一起会产生意想不到的结果。

**相等性测试和布尔字面值**

如果想测试一个算术对象或指针对象的真值，最直接的方法就是将其作为if语句的条件。

进行比较运算时除非比较的对象是布尔类型，否则不要使用布尔字面值作为运算对象。

# 4.4 赋值运算符

赋值运算符的左侧运算对象必须是一个可修改的左值。

赋值运算符的结果是它的左侧运算对象，并且是一个左值。

**赋值运算符满足右结合律**

**赋值运算符优先级较低**

因为赋值运算符的优先级低于关系运算符的优先级，所以在条件语句中，赋值部分应该加上括号。

**切勿混淆相等运算符和赋值运算符**

**复合赋值运算符**

我们经常需要对对象施加某种运算，然后把计算的结果再赋给该对象，这时候可是使用复合操作。

任意一种复合运算符都完全等价于：
```c++
a = a op b;

a = a + b;
a += b;
```

## 4.5 递增和递减运算符

递增运算符(++)和递减运算符(--)对对象的加1和减1操作提供了一种简洁的书写形式。

有前置版本和后置版本，前置版本将改变后的对象作为求值结果。后置版本的求值结果是运算对象改变之前那个值的副本。

这两种运算对象必须作用于左值运算对象。前置版本将运算对象本身作为左值返回，后置版本则将对象原始值的副本作为右值返回。

除非必须，否则不用递增递减运算符的后置版本。

**在一条语句中混用解引用和递增运算符**

如果我们想在一条复合表达式中即将变量加1或减1又能使用它原来的值，这时就可以使用递增和递减运算符的后置版本。

**运算对象可按任意顺序求值**

因为递增递减运算符会改变运算对象的值，所以要提防在复合表达式中错用这两个运算符。

```c++
while(beg != s.end() && !isspace(*beg))
    *beg = toupper(*beg++);  // 错误，该赋值语句未定义
```

上面程序的问题在于，赋值运算符左右两端的运算对象都用到了beg,并且右侧的运算对象还改变了beg的值，所以该赋值语句是未定义的。

## 4.6 成员访问运算符

点运算符和箭头运算符都可用于访问成员。表达式p->men等价于(*ptr).mem。

因为解引用运算符的优先级低于点运算，所以执行解引用的子表达式两端必须加上括号。

箭头运算符作用于一个指针类型的运算对象，结果是一个左值。点运算分成两种情况，如果成员所属的对象是左值，那么结果是左值；反之，如果成员所属的对象是右值，那么结果是右值。

## 4.7 条件运算符

条件运算符(?:)允许我们把简单的if-else逻辑嵌入到单个表达式当中，条件运算符按照如下形式使用：

```c++
cond ? expr1 : expr2;
```

首先qiucond的值，如果条件为真对expr1求值并返回该值，否则对expr2求值并返回。条件运算符只对两个表达式中的其中一个求值。

**嵌套条件运算符**

允许在条件运算符的内部嵌套另一个条件运算符。

条件运算符满足右结合律，意味着运算对象按照从右往左的顺序组合。

**在输出表达式中使用条件运算符**

条件运算符的优先级非常低，因此当一条长表达式中嵌套了条件运算子表达式时，通常需要在它两端加上括号。

```c++
cout << ((grade < 60) ? "fail" : "pass");  // 输出pass或者fail
cout << (grad < 60) ? "fail" : "pass";  // 输出1或者0
```

输出运算符`<<`的优先级高于条件运算符，因此第二条语句是先输出比较的结果，再通过cout的值来计算条件表达式。

## 4.8 位运算符

位运算符作用于整数类型的运算对象，并把运算对象看成是二进制位的集合。如果运算对象是小整型，则它的值会被自动提升成较大的整数类型。

关于符号位如何处理没有明确的规定，因此强烈建议仅将位运算符合用于处理无符号类型。

**移位运算符**

首先令左侧运算对象的内容按照右侧运算对象的要求移动指定位数，然后将经过移动的左侧运算对象的拷贝作为求值结果。

右侧运算对象一定不能是负数，而且值必须小于结果的位数，否则会产生未定义的行为。

左移(<<)或者右移(>>)到边界之外的位就被舍弃了。

**位求反运算符**

位求反运算符(~)将运算对象逐位求反后生成一个新值，将1置为0，将0置为1。

char类型的运算对象首先提升到int类型，往高位添加0，然后再逐位s取反。

**位与、位或、位异或运算符**

与(&) 或(|) 异或(^)运算符在两个运算对象逐位执行相应的逻辑操作。

对于异或运算符(^)而言，两个运算对象不同是为1，相同时为0。

**使用位运算符**

假设班级有30个学生，老师每周都会对学生进行一次小测验，测验的结果只有通过和不通过两种。为了更好地追踪测验的结果，我们用一个二进制位代表某个学生在一次测验中是否通过。

```c++
unsigned long quizl = 0; // 位的集合
quizl |= 1UL << 27;  // 表示学生27通过了测试
quizl &= ~(1UL << 27);  // 表示学生27通过了测试
bool status = quizl & (1UL << 27);  // 学生27是否通过测试
```

   **移位运算符满足左结合律**

IO操作符就是移位运算符的重载版本。

移位运算符的优先级不高不低，介于中间。比算术运算符的优先级低，但比关系运算符、赋值运算符和条件运算符的优先级高。

## 4.9 sizeof运算符

sizeof运算符返回一条表达式或一个类型名字所占的字节数。满足右结合律，其所得的值是一个size_t类型的常量表达式。运算符的运算对象有两种形式：

```c++
sizeof(type);
sizeof expr;  // 返回的是表达式结果类型的大小

sizeof *p;
```

在`sizeof`的运算对象中解引用一个无效指针仍然是一个安全的行为，因为指针实际上并没有被真正使用。

`sizeof`运算符的结果部分地依赖于其作用的类型：

- 对char或者类型为char的表达式执行`sizeof`运算，结果为1。
- 对引用类型执行sizeof运算得到被引用对象所占空间的大小。
- 对指针执行`sizeof`运算得到指针本身所占空间的大小。
- 对解引用指针执行`sizeof`运算得到指针指向的对象所占空间的大小，指针不需要有效。
- 对数组执行`sizeof`运算得到整个数组所占空间的大小。`sizeof`运算不会把数组转换成指针来处理。
- 对string对象或vector对象执行`sizeof`运算只返回该类型固定部分的大小，不会计算对象中的元素占用占用了多少空间。

## 4.10 逗号运算符

逗号运算符含有两个运算对象，按照从左到右的顺序依次求值。

对于逗号运算符来说，首先对左侧的表达式求值，然后将求值结果抛弃。逗号运算符真正的结果是右侧表达式的值。

逗号运算符常被用在for循环当中。

## 4.11 类型转换

如果两种类型有关联，那么当程序需要其中一种类型的运算对象时，可以用另一种关联类型的对象或值来代替。

有些类型的转换时自动执行的，无须程序员的介入，它们被称为隐式转换。

### 4.11.1 算术转换

算术转换的含义是把一种算术类型转换成另一种算术类型。

**整型提升**

 整型提升负责把小整数类型转换成较大的整数类型。

**无符号类型的运算对象**

首先执行整型提升，如果结果的类型匹配，无须进行进一步的转换。如果两个运算对象的类型要么都是带符号的、要么都是无符号的，则小类型的运算对象转换成较大的类型。

### 4.11.2 其他隐式类型转换

除了算术转换之外还有几种隐式类型转换：

**数组转换成指针**：在大多数用到数组的表达式中，数组自动转换成指向数组首元素的指针。

当数组被用作decltype关键字的参数，或者作为取地址符(&)、sizeof及typeid等运算符的运算对象时，或者用一个引用来初始化数组，上述转换不会发生。

**指针的转换：**常数值0或者字面值nullptr能转换成任意指针类型；指向任意非常量的指针能转换成void*;指向任意对象的指针能转换成const void\*。

**转换成布尔类型**：如果指针或算术类型的值为0，转换结果为false，否则转换结果是true。

**转换成常量：**允许将指向非常量类型的指针转换成指向相应的常量类型的指针，对于引用也是这样。

类类型定义的转换：类类型能定义由编译器自动执行的转换，不过编译器每次只能执行一种类类型的转换。

### 4.11.3 显式转换

有时候我们希望显示地将对象强制转换成另外一种类型，这种方法称为强制类型转换。

虽然有时候不得不使用强制类型转换，但这种方法本质上是非常危险的。

**命名的强制类型转换**

一个命名的强制类型转换具有如下形式：

```c++
cast-name<type>(expression);
```

其中，type是转换的目标类型而expression是要转换的值。如果type是引用类型，则结果是左值。cast-name是static_cast、dynamic_cast、const_cast、reinterpret_cast中一种，dynamic_cast支持运行时类型识别。

**static_cast**

任何具有明确定义的类型转换，只要不包含底层const，都可以使用static_cast。

**const_cast**

const_cast只能改变对象的底层const。

如果对象本身不是一个常量，使用强制类型转换获得写权限是合法的行为。

而如果对象是一个常量，再使用const_cast执行写操作就会产生未定义的后果。

**reinterprete_cast**

reinterprete_cast通常为运算对象的位模式提供较低层次上的重新解释。

**建议：避免强制类型转换**

强制类型转换干扰了正常的类型检查，因此程序员应该避免使用强制类型转换。

**旧式的强制类型转换**

在早期的C++语言中，显示地进行强制类型转换包含两种形式：

```c++
type (expr);  // 函数形式

(type) expr;  // C语言风格
```

当我们在某处执行旧式地强制类型转化时，如果转换成const_cast和static_cast也合法，则其行为与对应地命名转换一致。

如果替换后不合法，则旧式强制类型转换执行与reinterprete_cast类似的功能。

与命名的强制类型转换相比，旧式的强制类型转换从表现形式上来说不那么清晰明了。一旦转换过程出现问题，追踪起立也更加困难。

## 4.12 运算符优先级表

P147。









