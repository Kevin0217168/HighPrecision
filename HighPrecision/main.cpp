#define _CRT_SECURE_NO_WARNINGS
#include "HighPrecision.h"
#include <iostream>

using namespace std;

//int fb(HighPrecision n) {
//	if (n <= 2) {
//		return 0;
//	}
//	return fb(n - 1) + fb(n - 2);
//}

int main(void) {
	freopen("test.in", "r", stdin);

	HighPrecision a, b;
	cin >> a >> b;
	// TODO 运算符冲突
	// cout << a + 3 << endl;
	cout << 3 + a << endl;


	return 0;
}
