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
	/*------------------ʵ���� hp_basic.cpp ��---------------------*/

	// Ĭ�Ϲ��캯��
	HighPrecision();

	// �������캯����������Ҫ����Ķ������Ҫ�У�������
	// ���������ؾֲ������ʱ�򣬻��Զ����ô˺������п�������
	// ���û�У������Զ�������ַ�������ǵ�ַָ�������(ǳ����)
	HighPrecision(const HighPrecision&);
	// ��ֵ�����
	// ��������ֵʱ�Զ����ã��������������
	HighPrecision& operator=(const HighPrecision& other);

	// ����ת����������intתΪ�߾���
	HighPrecision(int);

	// �����������ͷſռ�
	~HighPrecision();

	// ���������л�ȡ����
	void get(istream& os);
	// ��ת����
	void reverse();
	// �������
	void display();
	// ��������
	int resize(int size);

	// ����
	friend istream& operator>>(istream& os, HighPrecision& other);
	// ���
	friend ostream& operator<<(ostream& os, const HighPrecision& other);
	

	/*------------------ʵ���� hp_add.cpp ��---------------------*/

	// �߾��ȼӸ߾���
	HighPrecision operator+(const HighPrecision& other) const;
	// ���ͼӸ߾���
	friend HighPrecision operator+(int, const HighPrecision& other);

private:
	
};

