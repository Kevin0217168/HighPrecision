#include <cstddef>

using namespace std;

class HighPrecision
{
private:
	// Ĭ������λ��
	int DEFAULT_SIZE = 20;

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

	// ���������л�ȡ����
	void get();

	// �������
	void display();

	// �ӷ���������һ������
	HighPrecision add(HighPrecision& other);

	// TODO ��������

private:
	void reverse();

};

