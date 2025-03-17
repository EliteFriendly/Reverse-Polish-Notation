#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#define M_PI 3.14159265358979323846

using namespace std;

class ReversePolishNot
{
	/*
	(,) - 0
	+,- - 1
	*,/ - 2
	^,sin,cos,exp,ln - 3
	*/



	stack <string> operators;//stack for operators
	stack <string> outLine;//Using for symbols and numbers

	string inputExpression;

	string* RPN;
	int lengthRPN;

	void convertToRPN();
	int getPriority(string op);
	void operationPriotity(string op);

public:
	ReversePolishNot(string str);
	~ReversePolishNot();


	double getResult(double* x);
	string printRPN();

};

