#include "HighPrecision.h"
#include <iostream>
#include<cstring>

using namespace std;

// �ӷ�
HighPrecision HighPrecision::operator+(const HighPrecision& other) const
{
	// �жϷ���

	// �Ƿ����
	// ����һ���������ڼ�ȥ����
	//if (this->flag == false && other.flag == true) return *this - other;
	// �෴
	//else if (this->flag == true && other.flag == false) return other - *this;

	// �����Ƚϳ�����ΪA
	const HighPrecision* A, * B;
	if (this->length > other.length) {
		A = this;
		B = &other;
	}
	else {
		A = &other;
		B = this;
	}

	// ��ʼ��һ������Ϊ���+1�Ķ��󣬴�Ž��
	HighPrecision result;
	result.resize(A->length + 1);

	// ͬ�ţ�����ѡ��������ͬ�ķ���
	result.flag = this->flag && other.flag;

	int carry = 0;
	for (int i = 0; i < A->length; i++) {
		// �������ڷ�Χ��
		if (i < B->length) {
			// ������ӣ���������һ���Ľ�λ
			result.data[i] = A->data[i] + B->data[i] + carry;
			// �ж��Ƿ���Ҫ��λ
			if (result.data[i] > 9) {
				carry = 1;
				// ��������λ��
				result.data[i] %= 10;
			}
			else {
				carry = 0;
			}
		}
		// ��С���Ѽ��ֻ꣬�ӽϴ���
		else {
			result.data[i] = A->data[i] + carry;
			// ����С���������ܳ��ֽ�λ����λ���9�� ���Ͻ�λ���10
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
	// ����λ�ӵ����λ���˴����λֻ����0��1
	result.data[A->length] = carry;
	// ��������Чλ���������Ƿ��λ�ı�־
	result.length = A->length + carry;

	return result;
}

HighPrecision operator+(int num, const HighPrecision& other) {
	return other + num;
}
