#include <cstddef>

using namespace std;

class HighPrecision
{
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

private:
	// Ĭ������λ��
	int DEFAULT_SIZE = 20;

	int* data = NULL;
	int max_length;
	int length;

};

