#include <iostream>
#include "ReversePolishNot.h"

using namespace std;

int main()
{




	string str = "4";
	ReversePolishNot rpn(str);
	cout<<rpn.printRPN();
	double x[1] = { 2 };
	cout << "Result: " << rpn.getResult(x) << endl;
	return 0;
}