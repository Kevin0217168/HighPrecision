#include <cstddef>
#include <iostream>
#include <cmath>

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
	bool flag = false;

	int size;
	int length = 0;

public:
	/*------------------实现在 hp_basic.cpp 中---------------------*/

	// 默认构造函数
	HighPrecision();

	// 拷贝构造函数（对于需要深拷贝的对象必须要有！！！）
	// 当函数返回局部对象的时候，会自动调用此函数进行拷贝副本
	// 如果没有，将会自动拷贝地址，而不是地址指向的数据(浅拷贝)
	HighPrecision(const HighPrecision&);
	// 赋值运算符
	// 当变量赋值时自动调用，进行深拷贝！！！
	HighPrecision& operator=(const HighPrecision& other);

	// 类型转换函数，将int转为高精度
	HighPrecision(int);

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

	// 比较数据的绝对值，返回绝对值较大数的引用
	HighPrecision compare(HighPrecision& A, HighPrecision& B);
	// 比较数据，返回较大数的引用
	const HighPrecision& absMax(const HighPrecision& A, const HighPrecision& B) const;

	// 输入
	friend istream& operator>>(istream& os, HighPrecision& other);
	// 输出
	friend ostream& operator<<(ostream& os, const HighPrecision& other);

	// 转换为int类型
	operator int() {
		cout << "调用我啦" << endl;
		int sum = 0;
		for (int i = this->length - 1; i >= 0; i--) {
			sum += this->data[i] * pow(10, (this->length - i - 1));
		}
		return sum;
	}

	/*------------------实现在 hp_add.cpp 中---------------------*/

	// 高精度加高精度
	HighPrecision operator+(const HighPrecision& other) const;
	// 整型加高精度
	friend HighPrecision operator+(int, const HighPrecision& other);

	/*------------------实现在 hp_sub.cpp 中---------------------*/

	// 高精度减高精度
	HighPrecision operator-(const HighPrecision& other) const;

	/*------------------实现在 hp_compare.cpp 中---------------------*/
	// 高精度等于高精度
	bool operator==(const HighPrecision& other) const;
	// 高精度小于等于高精度
	bool operator<=(const HighPrecision& other) const;

private:

};
