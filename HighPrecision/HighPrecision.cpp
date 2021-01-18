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
	// ��һ�������м�λ
	int count = countNum(num);
	// ����һ����ͬ��С�Ŀռ�
	this->resize(count);
	// �����ݵ�ÿһλ����
	int n = 0;
	for (int i = num; i; i /= 10) {
		this->data[n] = i % 10;
		n++;
	}
	this->length = count;
	// ���Լ���ת
	this->reverse();
}

HighPrecision::HighPrecision(const HighPrecision& other)
{
	// ֱ��ʹ�������������'='
	*this = other;
}

HighPrecision::~HighPrecision()
{
	cout << "awsl" << endl;
	delete[] this->data;
}

// ���������л�ȡ����
// ʱ�临�Ӷȣ�O(n)
void HighPrecision::get(istream& os)
{
	// �������Ϊ�գ����Զ��½�
	if (this->data == NULL) {
		this->resize(this->DEFAULT_SIZE);
	}

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
		// ��������
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

// ��ֵ���������
HighPrecision& HighPrecision::operator=(const HighPrecision& other)
{
	// ���Ҫ���Ƶ�����������Բ���
	if (this == &other) return *this;
	// ����ԭ����
	delete[] this->data;
	// �½�һ����������һ����Ĵ���ռ�
	this->data = new int[other.length];
	// �����ƶ�����
	memcpy(this->data, other.data, sizeof(int) * other.length);

	// ���Ը���
	this->length = other.length;
	this->size = other.size;
	this->flag = other.flag;
	this->DEFAULTSTEP = other.DEFAULT_SIZE;

	// ���ص�ǰ���ã�����������ֵ
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
		cerr << "�������õ������С������!" << endl;
		return -1;
	}

	int* new_data = new int[size];
	memcpy(new_data, this->data, sizeof(int) * this->length);
	delete[] this->data;
	this->data = new_data;

	this->size = size;

	return 0;
}