#include <cstddef>

using namespace std;

class HighPrecision
{
private:
	// 默认数据位数
	int DEFAULT_SIZE = 20;

	// 数据指针
	int* data = NULL;
	// 符号位，负真正假
	bool flag;

	int size;
	int length = 0;

public:
	// 构造函数，使用默认位数构建
	HighPrecision();
	// 传入数据位数
	HighPrecision(int);

	// 从输入流中获取数据
	void get();

	// 输出数据
	void display();

	// 加法，传入另一个加数
	HighPrecision add(HighPrecision& other);

	// TODO 扩容数据

private:
	void reverse();

};

