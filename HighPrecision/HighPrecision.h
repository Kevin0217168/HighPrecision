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
	// 传入数据位数
	HighPrecision(int);
	// 传入常量初始化
	const HighPrecision constNum(int) const;

	// 从输入流中获取数据
	void get();

	// 输出数据
	void display() const;

	// 扩容数据
	int resize(int size);

	// 加法，传入另一个加数
	HighPrecision operator+(const HighPrecision& other) const;
	// 加法重载，加上一个常数
	HighPrecision operator+(int) const;
	// 加法重载
	friend HighPrecision& operator<<(int, const HighPrecision& other);

	// 输出
	friend ostream& operator<<(ostream& os, const HighPrecision& other);

private:
	void reverse();



};

