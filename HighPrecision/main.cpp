#include "HighPrecision.h"
#include <iostream>

using namespace std;

int main(void) {
	HighPrecision a, b;
	a.get();
	b.get();

	HighPrecision c = a + b;
	cout << "  " << a << "\n+ " << b << "\n-----------\n  " << (a + b) << endl;

	cout << a << " + 1" << " = " << a + 1 << endl;

	return 0;
}