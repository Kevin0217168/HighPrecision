#define _CRT_SECURE_NO_WARNINGS
#define CATCH_CONFIG_MAIN  // 当前宏强制Catch在当前编译单元中创建 main()，这个宏只能出现在一个CPP文件中，因为一个项目只能有一个有效的main函数
#include "catch.hpp"

#include "HighPrecision.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

long long int radomInt(long long int a, long long int b) {
	return (rand() % (b - a + 1)) + a;
}

TEST_CASE("add", "[add][in text]") {
	srand((unsigned)time(NULL));

	freopen("test.in", "r", stdin);

	HighPrecision a, b;

	cin >> a >> b;
	CHECK(a + b == HighPrecision(3333));
	cin >> a >> b;
	CHECK(a + b == HighPrecision(21110));
	cin >> a >> b;
	CHECK(a + b == HighPrecision(90314369));
}

TEST_CASE("sub", "[sub][in text]") {
	HighPrecision a, b;

	cin >> a >> b;
	CHECK(a - b == HighPrecision(2222));
	cin >> a >> b;
	CHECK(a - b == HighPrecision(1000));
	cin >> a >> b;
	CHECK(a - b == HighPrecision(999));
	cin >> a >> b;
	CHECK(a - b == HighPrecision(-999));
	cin >> a >> b;
	CHECK(a - b == HighPrecision(1001));
	cin >> a >> b;
	CHECK(a - b == HighPrecision(0));
}

TEST_CASE("radom test add and sub", "[sub][in text]") {
	long long int min = -10000;
	long long int max = 10000;
	for (int i = 0; i < 10; i++) {
		long long int a = radomInt(min, max);
		long long int b = radomInt(min, max);
		if (radomInt(0, 1)) {
			INFO("加法");
			// cout << a << " + " << b << endl;
			INFO(a);
			INFO(b);
			CHECK(HighPrecision(a) + HighPrecision(b) == HighPrecision(a + b));
		}
		else {
			INFO("减法");
			INFO(a);
			INFO(b);
			CHECK(HighPrecision(a) - HighPrecision(b) == HighPrecision(a - b));
		}
	}

}

int fb(HighPrecision n) {
	if (n <= HighPrecision(2)) {
		return 1;
	}
	return fb(n - (HighPrecision)1) + fb(n - (HighPrecision)2);
}
