#include "HighPrecision.h"
#include <iostream>
#include<cstring>

using namespace std;

HighPrecision::HighPrecision(){}

int countNum(int n)
{
	int tmp = 0;
	do
	{
		n /= 10;
		tmp++;
	} while (n != 0);

	return tmp;
}

HighPrecision::HighPrecision(int num)
{
	// 数一数数据有几位
	int count = countNum(num);
	// 设置一个相同大小的空间
	this->resize(count);
	// 将数据的每一位填入
	int n = 0;
	for (int i = num; i; i /= 10) {
		this->data[n] = i % 10;
		n++;
	}
	this->length = count;
	// 将自己反转
	this->reverse();
}

HighPrecision::HighPrecision(const HighPrecision& other)
{
	// 直接使用了重载运算符'='
	*this = other;
}

HighPrecision::~HighPrecision()
{
	cout << "awsl" << endl;
	delete[] this->data;
}

// 从输入流中获取数据
// 时间复杂度：O(n)
void HighPrecision::get(istream& os)
{
	// 如果数组为空，则自动新建
	if (this->data == NULL) {
		this->resize(this->DEFAULT_SIZE);
	}

	// 数组尾指针
	int* p = this->data;
	this->length = 0;

	// 判断符号
	*p = os.get();
	if (*p == '-') {
		// 如果是负号，符号位置为真
		this->flag = true;
	}
	else {
		this->flag = false;
		// 如果是数据，转换为数字
		*p -= '0';
		p++;
		this->length++;
	}

	// TODO 未判断数据<=1的情况
	while (1) {
		// 读入数据
		while (this->length < this->size) {
			// 存入数据
			*p = os.get();
			// 判断停止条件
			if (*p == '\n' || *p == '\0' || *p == EOF) {
				// 反向存储数组
				this->reverse();
				return;
			};
			// 字符转数字
			*p -= '0';
			// 有效数据+1
			this->length++;
			// 指针前移一位
			p++;
		}
		// 数组扩容
		resize(this->size + this->DEFAULTSTEP);
		// 重置指针位置
		p = this->data + this->length;
	}
}

// 双指针反转数据
// 时间复杂度：O(n/2)
void HighPrecision::reverse()
{
	
	int* L = this->data;
	int* R = this->data + this->length - 1;
	while (L <= R) {
		int temp = *L;
		*L = *R;
		*R = temp;

		L++;
		R--;
	}
}

// 输出
void HighPrecision::display()
{
	// 如果有符号，先输出符号
	if (this->flag) cout << '-';
	// 反向输出
	for (int* p = this->data + this->length - 1; p >= this->data; p--) {
		cout << *p;
	}
}

// 赋值运算符重载
HighPrecision& HighPrecision::operator=(const HighPrecision& other)
{
	// 如果要复制的是自身，则忽略操作
	if (this == &other) return *this;
	// 销毁原数据
	delete[] this->data;
	// 新建一块与新数据一样大的储存空间
	this->data = new int[other.length];
	// 批量移动数据
	memcpy(this->data, other.data, sizeof(int) * other.length);

	// 属性复制
	this->length = other.length;
	this->size = other.size;
	this->flag = other.flag;
	this->DEFAULTSTEP = other.DEFAULT_SIZE;

	// 返回当前引用，方便连续赋值
	return *this;
}

// 加法
HighPrecision HighPrecision::operator+(const HighPrecision& other) const
{
	// 判断符号

	// 是否异号
	// 加上一个负数等于减去正数
	//if (this->flag == false && other.flag == true) return *this - other;
	// 相反
	//else if (this->flag == true && other.flag == false) return other - *this;

	// 将长度较长的作为A
	const HighPrecision* A, * B;
	if (this->length > other.length) {
		A = this;
		B = &other;
	}
	else {
		A = &other;
		B = this;
	}

	// 初始化一个长度为最长数+1的对象，存放结果
	HighPrecision result;
	result.resize(A->length + 1);

	// 同号，符号选择与其相同的符号
	result.flag = this->flag && other.flag;

	int carry = 0;
	for (int i = 0; i < A->length; i++) {
		// 两数都在范围内
		if (i < B->length) {
			// 两数相加，并加上上一数的进位
			result.data[i] = A->data[i] + B->data[i] + carry;
			// 判断是否需要进位
			if (result.data[i] > 9) {
				carry = 1;
				// 放入结果个位数
				result.data[i] %= 10;
			}
			else {
				carry = 0;
			}
		}
		// 较小数已加完，只加较大数
		else {
			result.data[i] = A->data[i] + carry;
			// 当最小数加完后可能出现进位，单位最大9， 加上进位最多10
			if (i == B->length) {
				if (result.data[i] > 9) {
					result.data[i] = 0;
				}
				else {
					carry = 0;
				}
			}
		}
		
	}
	// 将进位加到最高位，此处最高位只能是0或1
	result.data[A->length] = carry;
	// 计算结果有效位数，加上是否进位的标志
	result.length = A->length + carry;

	return result;
}

HighPrecision operator+(int num, const HighPrecision& other) {
	return other + num;
}

// 输出运算符重载
ostream& operator<<(ostream& os, const HighPrecision& other)
{
	// 如果有符号，先输出符号
	if (other.flag) os << '-';
	// 反向输出
	for (int* p = other.data + other.length - 1; p >= other.data; p--) {
		os << *p;
	}
	return os;
}

istream& operator>>(istream& os, HighPrecision& other)
{
	other.get(os);
	return os;
}

// 重新分配内存
int HighPrecision::resize(int size)
{
	if (size <= this->length) {
		cerr << "重新设置的数组大小无意义!" << endl;
		return -1;
	}

	int* new_data = new int[size];
	memcpy(new_data, this->data, sizeof(int) * this->length);
	delete[] this->data;
	this->data = new_data;

	this->size = size;

	return 0;
}