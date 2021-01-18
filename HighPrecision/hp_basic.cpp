#include "HighPrecision.h"
#include <iostream>
#include<cstring>

using namespace std;

HighPrecision::HighPrecision() {}

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

// �������������
istream& operator>>(istream& os, HighPrecision& other)
{
	other.get(os);
	return os;
}