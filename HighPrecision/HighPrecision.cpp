#include "HighPrecision.h"
#include <iostream>

using namespace std;

HighPrecision::HighPrecision()
{
	this->data = new int[this->DEFAULT_SIZE];
	this->max_length = this->DEFAULT_SIZE;
}

HighPrecision::HighPrecision(int size)
{
	this->data = new int[size];
	this->max_length = size;
}

void HighPrecision::get()
{
	// 数组尾指针
	int* p = this->data + this->max_length-1;
	this->length = 0;
	while (this->length < this->max_length) {
		// 存入数据
		*p = getchar();
		// 判断停止条件
		if (*p == '\n' || *p == '\0' || *p == EOF) break;
		// 字符转数字
		*p = *p - '0';
		// 有效数据+1
		this->length++;
		// 指针前移一位
		p--;
	}
}

void HighPrecision::display()
{
	for (int i = this->length-1; i >= 0; i--) {
		cout << this->data[i];
	}
}


HighPrecision HighPrecision::add(HighPrecision& other)
{

}