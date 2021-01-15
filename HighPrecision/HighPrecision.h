#include <cstddef>
#include <iostream>

using namespace std;

class HighPrecision
{
private:
	// Ĭ������λ��
	int DEFAULT_SIZE = 20;
	// Ĭ��������
	int DEFAULTSTEP = 10;

	// ����ָ��
	int* data = NULL;
	// ����λ����������
	bool flag;

	int size;
	int length = 0;

public:
	// ���캯����ʹ��Ĭ��λ������
	HighPrecision();
	// ��������λ��
	HighPrecision(int);
	// ���볣����ʼ��
	const HighPrecision constNum(int) const;

	// ���������л�ȡ����
	void get();

	// �������
	void display() const;

	// ��������
	int resize(int size);

	// �ӷ���������һ������
	HighPrecision operator+(const HighPrecision& other) const;
	// �ӷ����أ�����һ������
	HighPrecision operator+(int) const;
	// �ӷ�����
	friend HighPrecision& operator<<(int, const HighPrecision& other);

	// ���
	friend ostream& operator<<(ostream& os, const HighPrecision& other);

private:
	void reverse();



};

