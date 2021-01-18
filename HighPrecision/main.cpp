#define _CRT_SECURE_NO_WARNINGS
#include "HighPrecision.h"
#include <iostream>

using namespace std;

int main(void) {
	freopen("test.in", "r", stdin);

	HighPrecision a, b;
	cin >> a >> b;

	cout << 2 + a + b << endl;

	return 0;
}