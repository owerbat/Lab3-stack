#include "Stack.h"
#include "TCalculator.h"
#include <Bits.h>

int main() {
	
	cout << "Calculate: ";
	string str;
	cin >> str;

	TCalculator result(str);
	cout << "Result: " << result.calc() << endl;

	return 0;
}