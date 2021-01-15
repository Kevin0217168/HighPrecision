#include "HighPrecision.h"
#include <iostream>

using namespace std;

HighPrecision::HighPrecision()
{
	this->data = new int[this->DEFAULT_SIZE];
	this->size = this->DEFAULT_SIZE;
}

HighPrecision::HighPrecision(int size)
{
	this->data = new int[size];
	this->size = size;
}

/*
时间复杂度：O(n)
*/
void HighPrecision::get()
{
	// 数组尾指针
	int* p = this->data;
	this->length = 0;

	// TODO 数组自动扩容

	// 判断符号
	*p = getchar();
	if (*p == '-') {
		// 如果是负号，符号位置为真
		this->flag = true;
	}
	else {
		this->flag = false;
		// 如果是数据，转换为数字
		p -= '0';
		p++;
		this->length++;
	}
	// 读入数据
	while (this->length < this->size) {
		// 存入数据
		*p = getchar();
		// 判断停止条件
		if (*p == '\n' || *p == '\0' || *p == EOF) break;
		// 字符转数字
		*p = *p - '0';
		// 有效数据+1
		this->length++;
		// 指针前移一位
		p++;
	}

	// 反向存储数组
	this->reverse();

}

void HighPrecision::display()
{
	for (int i = 0; i < this->length; i++) {
		cout << this->data[i];
	}
}


HighPrecision HighPrecision::add(HighPrecision& other)
{
	return HighPrecision();
}

/*
时间复杂度：O(n/2)
*/
void HighPrecision::reverse()
{
	// 双指针反转数据
	int* L = this->data;
	int* R = this->data + this->length - 1;
	while(L <= R) {
		int temp = *L;
		*L = *R;
		*R = temp;

		L++;
		R--;
	}
}
