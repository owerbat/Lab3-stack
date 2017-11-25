#include "Stack.h"
#include "TCalculator.h"

int main() {
	TCalculator a("(2+3*4)^2");
	if (a.check()) {
		cout << "OK" << endl;
	}
	else
		cout << "NOT OK" << endl;
	cout << a.getinfix() << endl;
	cout << a.getpostfix() << endl << "res = " << a.calc() << endl;

	return 0;
}