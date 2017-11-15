#include "TCalculator.h"

int TCalculator::check() {
	stc.clear();
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(')
			stc.push('(');
		if (infix[i] == ')') {
			if (stc.isempty())
				return 0;
			stc.pop();
		}
	}
	if (stc.isempty())
		return 1;
	return 0;
}

int TCalculator::priority(char sym) {
	switch (sym) {
	case '(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default: return -1;
	}
}

void TCalculator::topostfix() {
	if (check()) {
		postfix = "";
		stc.clear();
		string buf = '(' + infix + ')';
		for (int i = 0; i < buf.size(); i++) {
			if (buf[i] == '(')
				stc.push('(');
			if ((buf[i] <= '9' && buf[i] >= '0') || buf[i] == '.')
				postfix += buf[i];
			if (buf[i] == ')') {
				char el = stc.pop();
				while (el != '(') {
					postfix += el;
					el = stc.pop();
				}
			}
			if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' || buf[i] == '^') {
				postfix += " ";
				while (priority(buf[i]) <= priority(stc.top())) {
					postfix += stc.pop();
				}
				stc.push(buf[i]);
			}
		}
	}
	else
		throw - 3;
}

double TCalculator::calc() {
	topostfix();
	StD.clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double op1, op2;
			op2 = StD.pop();
			op1 = StD.pop();
			switch (postfix[i]) {
			case '+': StD.push(op1 + op2); break;
			case '-': StD.push(op1 - op2); break;
			case '*': StD.push(op1 * op2); break;
			case '/': StD.push(op1 / op2); break;
			case '^': StD.push(pow(op1, op2)); break;
			}
		}
		if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.') {
			char* tmp;
			double res = strtod(&postfix[i], &tmp);
			int di = tmp - &postfix[i];
			i += di - 1;
			StD.push(res);
		}
	}
	double result = StD.pop();
	if (!StD.isempty())
		throw - 2;
	return result;
}