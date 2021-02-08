#include "HighPrecision.h"
#include <iostream>

using namespace std;

bool HighPrecision::operator==(const HighPrecision& other) const
{
	if (this->flag == other.flag) {
		if (this->length == other.length) {
			for (int i = this->length - 1; i >= 0; i--) {
				if (other.data[i] != other.data[i]) {
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

bool HighPrecision::operator<=(const HighPrecision& other) const
{
	HighPrecision result = *this - other;
	if (result.flag == true) return true;
	else return false;
}
