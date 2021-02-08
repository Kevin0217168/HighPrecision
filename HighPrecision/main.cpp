#define _CRT_SECURE_NO_INFOINGS
#define CATCH_CONFIG_MAIN  // 当前宏强制Catch在当前编译单元中创建 main()，这个宏只能出现在一个CPP文件中，因为一个项目只能有一个有效的main函数
#include "catch.hpp"

#include "HighPrecision.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

long long int randInt(long long int a, long long int b) {
	return (rand() % (b - a + 1)) + a;
}

TEST_CASE("test add in text", "[add][in text]") {
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

TEST_CASE("test sub in text", "[sub][in text]") {
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

TEST_CASE("test add and sub in random", "[sub and add][radom]") {
	long long int min = -10000;
	long long int max = 10000;
	for (int i = 0; i < 10; i++) {
		long long int a = randInt(min, max);
		long long int b = randInt(min, max);
		if (randInt(0, 1)) {
			INFO("加法");
			// cout << a << " + " << b << endl;
			INFO(a << " + " << b);
			CHECK(HighPrecision(a) + HighPrecision(b) == HighPrecision(a + b));
		}
		else {
			INFO("减法");
			INFO(a << " - " << b);
			CHECK(HighPrecision(a) - HighPrecision(b) == HighPrecision(a - b));
		}
	}

}

TEST_CASE("test compare in random", "[compare][radom]") {
	long long int min = -1000;
	long long int max = 1000;
	for (int i = 0; i < 10; i++) {
		long long int a = randInt(min, max);
		long long int b = randInt(min, max);
		int c = randInt(0, 4);
		if (c == 0) {
			bool result = HighPrecision(a) == HighPrecision(b);
			INFO(a << " == " << b << " result: " << result);
			CHECK(result == (a == b));
		}
		else if (c == 1) {
			bool result = HighPrecision(a) > HighPrecision(b);
			INFO(a << " > " << b << " result: " << result);
			CHECK(result == (a > b));
		}
		else if (c == 2) {
			bool result = HighPrecision(a) < HighPrecision(b);
			INFO(a << " < " << b << " result: " << result);
			CHECK(result == (a < b));

		}
		else if (c == 3) {
			bool result = HighPrecision(a) <= HighPrecision(b);
			INFO(a << " <= " << b << " result: " << result);
			CHECK(result == (a <= b));
		}
		else if (c == 4) {
			bool result = HighPrecision(a) >= HighPrecision(b);
			INFO(a << " >= " << b << " result: " << result);
			CHECK(result == (a >= b));
		}
	}
}

HighPrecision fb(HighPrecision n) {
	if (n == HighPrecision(1)) {
		return 0;
	}
	else if (n == HighPrecision(2)) {
		return 1;
	}
	return fb(n - (HighPrecision)1) + fb(n - (HighPrecision)2);
}

long long int fb(long long int n) {
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	return fb(n - 1) + fb(n - 2);
}

TEST_CASE("test fb", "[compare][add and sub]") {
	long long int min = 1;
	long long int max = 20;
	for (int i = 0; i < 10; i++) {
		long long int n = randInt(min, max);

		CHECK(fb((HighPrecision)n) == (HighPrecision)fb(n));

	}
}
