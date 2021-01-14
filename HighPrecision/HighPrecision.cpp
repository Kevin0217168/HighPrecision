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
	// ����βָ��
	int* p = this->data + this->max_length-1;
	this->length = 0;
	while (this->length < this->max_length) {
		// ��������
		*p = getchar();
		// �ж�ֹͣ����
		if (*p == '\n' || *p == '\0' || *p == EOF) break;
		// �ַ�ת����
		*p = *p - '0';
		// ��Ч����+1
		this->length++;
		// ָ��ǰ��һλ
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