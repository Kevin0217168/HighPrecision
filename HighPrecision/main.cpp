#define _CRT_SECURE_NO_WARNINGS
#include "HighPrecision.h"
#include <iostream>

using namespace std;

int main(void) {
	freopen("test.in", "r", stdin);

	HighPrecision a, b;
	cin >> a >> b;

	cout << a << "\n" << b << endl;
	HighPrecision c = a + b;
	cout << c << endl;
	//cout << a + b << endl;
	//cout << a + HighPrecision::constNum(111) << endl;
	//cout << a + 111 << endl;
	//cout << 111 + a << endl;

	return 0;
}