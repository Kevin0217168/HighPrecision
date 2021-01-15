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
ʱ�临�Ӷȣ�O(n)
*/
void HighPrecision::get()
{
	// ����βָ��
	int* p = this->data;
	this->length = 0;

	// TODO �����Զ�����

	// �жϷ���
	*p = getchar();
	if (*p == '-') {
		// ����Ǹ��ţ�����λ��Ϊ��
		this->flag = true;
	}
	else {
		this->flag = false;
		// ��������ݣ�ת��Ϊ����
		p -= '0';
		p++;
		this->length++;
	}
	// ��������
	while (this->length < this->size) {
		// ��������
		*p = getchar();
		// �ж�ֹͣ����
		if (*p == '\n' || *p == '\0' || *p == EOF) break;
		// �ַ�ת����
		*p = *p - '0';
		// ��Ч����+1
		this->length++;
		// ָ��ǰ��һλ
		p++;
	}

	// ����洢����
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
ʱ�临�Ӷȣ�O(n/2)
*/
void HighPrecision::reverse()
{
	// ˫ָ�뷴ת����
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
