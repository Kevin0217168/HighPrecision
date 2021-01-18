#include "HighPrecision.h"
#include <iostream>
#include<cstring>

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

HighPrecision::~HighPrecision()
{
	cout << "awsl" << endl;
	delete[] this->data;
}

HighPrecision::HighPrecision(const HighPrecision& other)
{
	cout << "aaa" << endl;
	delete[] this->data;
	this->data = new int[other.length];
	memcpy(this->data, other.data, sizeof(int) * other.length);

	this->length = other.length;
	this->size = other.size;
	this->flag = other.flag;
}

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

static HighPrecision constNum(const int num)
{
	int count = countNum(num);
	HighPrecision result(count);
	int n = 0;
	for (int i = num; i; i /= 10) {
		result.getData()[n] = i % 10;
		n++;
	}
	result.reverse();
	return result;
}

// ���������л�ȡ����
// ʱ�临�Ӷȣ�O(n)
void HighPrecision::get(istream& os)
{
	// ����βָ��
	int* p = this->data;
	this->length = 0;

	// �жϷ���
	*p = os.get();
	if (*p == '-') {
		// ����Ǹ��ţ�����λ��Ϊ��
		this->flag = true;
	}
	else {
		this->flag = false;
		// ��������ݣ�ת��Ϊ����
		*p -= '0';
		p++;
		this->length++;
	}

	// TODO δ�ж�����<=1�����
	while (1) {
		// ��������
		while (this->length < this->size) {
			// ��������
			*p = os.get();
			// �ж�ֹͣ����
			if (*p == '\n' || *p == '\0' || *p == EOF) {
				// ����洢����
				this->reverse();
				return;
			};
			// �ַ�ת����
			*p -= '0';
			// ��Ч����+1
			this->length++;
			// ָ��ǰ��һλ
			p++;
		}
		resize(this->size + this->DEFAULTSTEP);
		// ����ָ��λ��
		p = this->data + this->length;
	}
}

// ˫ָ�뷴ת����
// ʱ�临�Ӷȣ�O(n/2)
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

// ���
void HighPrecision::display()
{
	// ����з��ţ����������
	if (this->flag) cout << '-';
	// �������
	for (int* p = this->data + this->length - 1; p >= this->data; p--) {
		cout << *p;
	}
}

HighPrecision& HighPrecision::operator=(const HighPrecision& other)
{
	if (this == &other) return *this;
	cout << "haha" << endl;
	delete[] this->data;
	this->data = new int[other.length];
	memcpy(this->data, other.data, sizeof(int) * other.length);

	this->length = other.length;
	this->size = other.size;
	this->flag = other.flag;
	return *this;
}

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
	HighPrecision result(A->length + 1);

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

//HighPrecision HighPrecision::operator+(int other) const
//{
//	HighPrecision result = constNum(other);
//	return result + *this;
//}

//HighPrecision operator+(int num, HighPrecision& other)
//{
//	return(constNum(num) + other);
//}

// ������������
ostream& operator<<(ostream& os, const HighPrecision& other)
{
	// ����з��ţ����������
	if (other.flag) os << '-';
	// �������
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

// ���·����ڴ�
int HighPrecision::resize(int size)
{
	if (size <= this->length) {
		return -1;
	}

	int* new_data = new int[size];
	memcpy(new_data, this->data, sizeof(int) * this->length);
	delete[] this->data;
	this->data = new_data;

	this->size = size;

	return 0;
}