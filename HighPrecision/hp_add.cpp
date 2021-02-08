#include "HighPrecision.h"
#include <iostream>

using namespace std;

// 加法
HighPrecision HighPrecision::operator+(const HighPrecision& other) const
{
	// 判断符号

	// 是否异号
	// 加上一个负数等于减去正数
	if (this->flag == false && other.flag == true) {
		HighPrecision temp = other;
		temp.flag = false;
		return *this - temp;
	}
	// 相反
	else if (this->flag == true && other.flag == false) {
		HighPrecision temp = *this;
		temp.flag = false;
		return other - temp;
	}

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
