#pragma once

#include "stack.h"

class TCalculator {
	string infix;
	string postfix;
	TStack<char> stc;
	TStack<double> StD;
public:
	TCalculator(string _infix = "") : stc(_infix.size() + 1), StD(_infix.size() + 1) {
		infix = _infix;
	}

	void setinfix(string _infix) {
		infix = _infix;
	}
	string getinfix() {
		return infix;
	}
	string getpostfix() {
		return postfix;
	}

	int check();
	int priority(char sym);
	void topostfix();
	double calc();
};