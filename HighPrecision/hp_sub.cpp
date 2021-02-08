#include "HighPrecision.h"
#include <iostream>

using namespace std;

// 高精度减高精度
HighPrecision HighPrecision::operator-(const HighPrecision& other) const
{
	// 判断符号（加法情况）
	// 一正一负，等于正加正
	if (this->flag == false && other.flag == true) {
		HighPrecision temp = other;
		temp.flag = false;
		return *this + temp;
	}
	// 一负一正，等于绝对值相加后相反数
	else if (this->flag == true && other.flag == false) {
		HighPrecision temp = *this;
		// 将负数改为正数
		temp.flag = false;
		// 绝对值相加
		HighPrecision result = temp + other;
		// 最后结果为负数
		result.flag = true;
		return result;
	}

	// 两数相减，绝对值大的减绝对值小的，取绝对值较大的符号（减法情况）

	// 将绝对值较大的作为A
	const HighPrecision* A, * B;
	A = &this->absMax(*this, other);
	if (A == this) B = &other;
	else B = this;

	HighPrecision result;
	result.resize(A->length);
	// 绝对值较大的符号
	if (A == &other) result.flag = !A->flag;
	else result.flag = A->flag;


	int carry = 0;
	for (int i = 0; i < A->length; i++) {
		if (i < B->length) {
			result.data[i] = A->data[i] - B->data[i] + carry;
		}
		else {
			result.data[i] = A->data[i] + carry;
		}
		if (result.data[i] < 0) {
			result.data[i] += 10;
			carry = -1;
		}
		else {
			carry = 0;
		}
	}

	for (int i = A->length - 1; i >= 0; i--) {
		if (result.data[i] != 0) {
			result.length = i + 1;
			return result;
		}
	}
	result.length = 1;
	result.flag = false;
	return result;
}
