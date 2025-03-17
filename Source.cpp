#include <iostream>
#include "ReversePolishNot.h"

using namespace std;

int main()
{




	string str = "x1 + ln(1^(exp(20-10+4*17)/11)+x4)+pi";
	ReversePolishNot rpn(str);
	cout<<rpn.printRPN();
	double x[1] = { 2 };
	cout << "Result: " << rpn.getResult(x) << endl;
	return 0;
}