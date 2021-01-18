#define _CRT_SECURE_NO_WARNINGS
#include "HighPrecision.h"
#include <iostream>

using namespace std;

int fb(HighPrecision n) {
	if (n <= HighPrecision(2)) {
		return 1;
	}
	return fb(n - (HighPrecision)1) + fb(n - (HighPrecision)2);
}

int main(void) {
	freopen("test.in", "r", stdin);

	HighPrecision a, b;
	cin >> a >> b;
	// TODO 运算符冲突
	// cout << a + 3 << endl;

	cout << a - b << endl;

	return 0;
}
