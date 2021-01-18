#include <cstddef>
#include <iostream>

using namespace std;

class HighPrecision
{
private:
	// 默认数据位数
	int DEFAULT_SIZE = 20;
	// 默认扩容量
	int DEFAULTSTEP = 10;

	// 数据指针
	int* data = NULL;
	// 符号位，负真正假
	bool flag;

	int size;
	int length = 0;

public:
	// 构造函数，使用默认位数构建
	HighPrecision();

	// 拷贝构造函数（对于需要深拷贝的对象必须要有！！！）
	// 当函数返回局部对象的时候，会自动调用此函数进行拷贝副本
	// 如果没有，将会自动拷贝地址，而不是地址指向的数据(浅拷贝)
	HighPrecision(const HighPrecision&);
	// 类型转换函数，将int转为高精度
	HighPrecision(int);

	// 传入常量初始化
	//static HighPrecision constNum(const int);

	// 析构函数，释放空间
	~HighPrecision();

	// 从输入流中获取数据
	void get(istream& os);
	// 反转数据
	void reverse();
	// 输出数据
	void display();
	// 扩容数据
	int resize(int size);

	// 赋值运算符（对于需要深拷贝的对象必须要有！！！）
	// 当变量赋值时自动调用，进行深拷贝！！！
	HighPrecision& operator=(const HighPrecision& other);

	// 加法，传入另一个加数
	HighPrecision operator+(const HighPrecision& other) const;
	friend HighPrecision operator+(int, const HighPrecision& other);

	// 输出
	friend ostream& operator<<(ostream& os, const HighPrecision& other);
	// 输入
	friend istream& operator>>(istream& os, HighPrecision& other);
private:
	



};

