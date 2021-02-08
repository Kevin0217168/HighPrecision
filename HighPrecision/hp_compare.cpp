#include "HighPrecision.h"
#include <iostream>

using namespace std;

int HighPrecision::compare(const HighPrecision& a, const HighPrecision& b) const {
	// 两数是否同号
	if (a.flag == b.flag) {
		// 两数是否等长
		if (a.length == b.length) {
			// 比较每一数位
			for (int i = a.length - 1; i >= 0; i--) {
				if (a.data[i] > b.data[i]) {
					// 同负，绝对值大的反而小，同正，绝对值大的大
					return a.flag ? -1 : 1;
				}
				else if (a.data[i] < b.data[i]) {
					// 同负，绝对值小的反而大，同正，绝对值小的小
					return a.flag ? 1 : -1;
				}
			}
			// 每一数位相同，相等
			return 0;
		}
		else {

			if (a.flag) {
				// 同负，长的反而小
				return a.length > b.length ? -1 : 1;
			}
			else {
				// 同正，长的大
				return a.length > b.length ? 1 : -1;
			}
		}
	}
	else {
		// 异号，正数比负数大
		return a.flag ? -1 : 1;
	}
	return false;
}

bool HighPrecision::operator==(const HighPrecision& other) const
{
	return !this->compare(*this, other);
}

bool HighPrecision::operator<=(const HighPrecision& other) const
{
	int result = this->compare(*this, other);
	return result <= 0 ? true : false;
}

bool HighPrecision::operator>=(const HighPrecision& other) const
{
	int result = this->compare(*this, other);
	return result >= 0 ? true : false;
}

bool HighPrecision::operator<(const HighPrecision& other) const
{
	int result = this->compare(*this, other);
	return result < 0 ? true : false;
}

bool HighPrecision::operator>(const HighPrecision& other) const
{
	int result = this->compare(*this, other);
	return result > 0 ? true : false;
}
