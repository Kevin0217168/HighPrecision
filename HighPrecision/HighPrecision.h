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
	//static HighPrecision constNum(const int);

	~HighPrecision();

	// ���������л�ȡ����
	void get(istream& os);
	// ��ת����
	void reverse();
	// �������
	void display(ostream& os);
	// ��������
	int resize(int size);


	// �ӷ���������һ������
	HighPrecision operator+(const HighPrecision& other) const;
	/*HighPrecision operator+(int) const;
	friend HighPrecision operator+(int, HighPrecision& other);*/


	// ���
	friend ostream& operator<<(ostream& os, const HighPrecision& other);
	// ����
	friend istream& operator>>(istream& os, HighPrecision& other);

	int* getData() {
		return data;
	}

private:
	



};

