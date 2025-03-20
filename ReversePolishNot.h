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

	string inputExpression;//Input expression after adding spaces

	string* RPN;
	int lengthRPN;

	void convertToRPN();//Convert to Reverse Polish Notation
	int getPriority(string op);//Get priority of operation
	void operationPriotity(string op);//Rechange stack of operators with priority

public:
	ReversePolishNot(string str);
	ReversePolishNot();

	~ReversePolishNot();

	void setExpression(string str);
	double getResult(double* x);
	string printRPN();

};

