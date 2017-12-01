#include "Stack.h"
#include "TCalculator.h"
#include <Bits.h>

int main() {
	/*TCalculator a("(2+3*4)^2");
	if (a.check()) {
		cout << "OK" << endl;
	}
	else
		cout << "NOT OK" << endl;
	cout << a.getinfix() << endl;
	cout << a.getpostfix() << endl << "res = " << a.calc() << endl;*/


	TCalculator a("9+(5*45-(7+7^4)*5/(7*2+21/254)+4*9^6)*(7+34+9*(9+3+54^7/8-6+562-5)*6)/10^17");
	a.topostfix();
	double result = 9 + (5 * 45 - (7 + pow(7, 4)) * 5 / (7 * 2 + 21 / 254) + 4 * pow(9, 6))*(7 + 34 + 9 * (9 + 3 + pow(54, 7) / 8 - 6 + 562 - 5) * 6) / pow(10, 17);
	cout.precision(100);
	try {
		cout << a.calc() << endl << result << endl << endl;
	}
	catch (...) {
		cout << "error " << endl;
	}

	if (result == a.calc()) {
		cout << "OK" << endl;
	}
	else {
		cout << "NOT OK" << endl;
	}

	cout << "res-calc = " << result - a.calc() << endl;


	return 0;
}