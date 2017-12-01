#pragma once
#include <iostream>

using namespace std;

typedef long long unsigned int luint;

class BitNumber {
	double number;
	luint bnum;

	luint GetBitMask(int n) const {
		luint res = 1;
		res << n;
		return res;
	}
public:

	BitNumber(double num = 1.0) {
		number = num;
		bnum = 0;
	}

	void setbit(int n) {
		bnum |= GetBitMask(n);
	}

	void clrbit(int n) {
		bnum &= ~(GetBitMask(n));
	}

	int getbit(int n) {
		if ((bnum & GetBitMask(n)) == 0)
			return 0;
		return 1;
	}

	luint GetBitNum() {
		for (int i = 0; i < 64; i++) {

		}
	}
};