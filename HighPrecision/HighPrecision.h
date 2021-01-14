#include <cstddef>

using namespace std;

class HighPrecision
{
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

private:
	// 默认数据位数
	int DEFAULT_SIZE = 20;

	int* data = NULL;
	int max_length;
	int length;

};

