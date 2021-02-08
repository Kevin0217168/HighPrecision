# HighPrecision 高精度计算库

- 内存全部动态分配

* 包含加减运算、赋值运算、比较运算和输入输出
* 目前支持的：+、-、=、==、<、>、<=、>=、<<、>>
* TODO: 乘除运算、自增自减、计算赋值符

## 环境

### 开发

- windows 10 x64
- C++ 11
- VS2019

### 测试

- Catch2.hpp

## 使用方式

### 引入

将项目文件夹放置在可被引用的位置

```c++
#include "HighPrecision.h"
```

### 声明&定义

与int变量的使用方式一致

```c++
// 先声明再定义
HighPrecision a;
a = 123;
// 直接实例化
HighPrecision a(123);
// 创建指针
HighPrecision* p = new HighPrecision(123);
```

### 计算

暂不支持++、--、+=、-=等复合运算符

```c++
HighPrecision a = 123;
HighPrecision b = 345;
// 高精加高精
HighPrecision c = a + b; // 468
// 高精加常数
HighPrecision c = a + 123; // 246
// 常数加高精
HighPrecision c = 123 + b; // 468
```

### 比较

```c++
HighPrecision a = 123;
HighPrecision b = 345;

a == b;  // false
a < b;   // true
a <= b;  // true

a > 100;  // 运算符冲突
// 请使用以下两种方式，强制转换为同一类型
(int)a > 100;           // 数据较大时溢出
a > (HighPrecision)100; // 莫得问题
```

### 输入&输出

与iostream兼容

```c++
HighPrecision a;
// 输入
cin >> a;
// a.get();     与cin等效

// 输出
cout << "A: " << a << endl;
// a.display(); 与cout等效
```

## 参数

大部分参数都有注释，可详见源码

### 私有

| 字段         | 类型 | 初始值 | 意义                       |
| ------------ | ---- | ------ | -------------------------- |
| DEFAULT_SIZE | int  | 20     | 在无参构造时的默认数据长度 |
| DEFAULTSTEP  | int  | 10     | 在数据溢出时的默认扩容长度 |
| data         | int* | NULL   | 数据指针(数据倒序存储)     |
| flag         | bool | false  | 符号位，负真正假           |
| size         | int  | --     | 当前开辟的内存大小         |
| length       | int  | 0      | 当前数据的长度             |

## 函数

大部分函数都有注释，可详见源码

### 公有

#### 内联

| 字段         | 返回值     | 意义               |
| ------------ | ---------- | ------------------ |
| getsize      | const int  | 返回私有参数size   |
| getlength    | const int  | 返回私有参数length |
| getflag      | const bool | 返回私有参数flag   |
| getdata      | const int* | 返回私有参数data   |
| operator int | int        | 强制转换int        |

#### 实现在 hp_basic.cpp 中

| 字段           | 参一                       | 参二                 | 返值           | 意义                    |
| -------------- | -------------------------- | -------------------- | -------------- | ----------------------- |
| HighPrecision  | --                         | --                   | --             | 无参构造函数            |
| HighPrecision  | const HighPrecision&       | --                   | --             | 拷贝构造函数            |
| operator=      | const HighPrecision& other | --                   | HighPrecision& | 赋值运算符(同上)        |
| HighPrecision  | long long int              | --                   | --             | int转为高精度           |
| ~HighPrecision | --                         | --                   | --             | 析构函数                |
| get            | istream&                   | --                   | --             | 从输入流中获取数据(cin) |
| reverse        | --                         | --                   | --             | 反转数据                |
| display        | --                         | --                   | --             | 输出数据(cout)          |
| resize         | int                        | --                   | int            | 扩容数据(正常0错误-1)   |
| operator>>     | istream&                   | HighPrecision&       | istream&       | cin                     |
| operator<<     | ostream&                   | const HighPrecision& | ostream&       | cout                    |
|                |                            |                      |                |                         |

#### 实现在 hp_add.cpp 中

| 字段      | 参一                 | 参二                 | 返值          | 意义       |
| --------- | -------------------- | -------------------- | ------------- | ---------- |
| operator+ | const HighPrecision& | --                   | HighPrecision | 高精加高精 |
| operator+ | int                  | const HighPrecision& | HighPrecision | 整型加高精 |

#### 实现在 hp_sub.cpp 中

| 字段      | 参一                       | 参二 | 返值          | 意义       |
| --------- | -------------------------- | ---- | ------------- | ---------- |
| operator- | const HighPrecision& other | --   | HighPrecision | 高精减高精 |

#### 实现在 hp_compare.cpp 中

| 字段       | 参一                 | 参二                 | 返值                 | 意义                               |
| ---------- | -------------------- | -------------------- | -------------------- | ---------------------------------- |
| absMax     | const HighPrecision& | const HighPrecision& | const HighPrecision& | 比较数据的绝对值，返回较大数的引用 |
| compare    | const HighPrecision& | const HighPrecision& | int                  | 比较两数大小，小1等0大2            |
| operator== | const HighPrecision& | --                   | bool                 | 等于                               |
| operator<= | const HighPrecision& | --                   | bool                 | 小于等于                           |
| operator>= | const HighPrecision& | --                   | bool                 | 大于等于                           |
| operator<  | const HighPrecision& | --                   | bool                 | 小于                               |
| operator>  | const HighPrecision& | --                   | bool                 | 大于                               |

