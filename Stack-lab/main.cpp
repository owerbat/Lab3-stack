#include "Stack.h"
#include "TCalculator.h"

int main() {
	
	cout << "Calculate: ";
	string str;
	cin >> str;

	try {
		TCalculator result(str);
		cout << "Result: " << result.calc() << endl;
	}
	catch (...) {
		cout << "Input error\n";
	}

	return 0;
}