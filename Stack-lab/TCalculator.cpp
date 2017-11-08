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