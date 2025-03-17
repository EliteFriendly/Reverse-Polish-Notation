#include "ReversePolishNot.h"


void ReversePolishNot::convertToRPN()
{
	//Парсинг строки
	vector <string> tmpStack;
	string temp = "";
	//Преобразование строки в массив
	for (int i = 0; i < inputExpression.length(); i++)
	{
		if (inputExpression[i] == ' ')
		{
			if (temp != "")
			{
				tmpStack.push_back(temp);
				temp = "";
			}
		}
		else
		{
			temp += inputExpression[i];
		}
	}
	//Начало самого алгоритма
	for (int i = 0; i < tmpStack.size(); i++)
	{
		if (tmpStack[i] == "+" or 
			tmpStack[i] == "-" or 
			tmpStack[i] == "*" or 
			tmpStack[i] == "/" or 
			tmpStack[i] == "^" or 
			tmpStack[i] == "sin" or 
			tmpStack[i] == "cos" or 
			tmpStack[i] == "exp" or 
			tmpStack[i] == "ln")
		{
			operationPriotity(tmpStack[i]);
		}
		else if (tmpStack[i] == "(")
		{
			operators.push(tmpStack[i]);
		}
		else if (tmpStack[i] == ")")
		{
			while (operators.top() != "(")
			{
				outLine.push(operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else
		{
			outLine.push(tmpStack[i]);
		}
	}
	//Очистка стека операторов
	while (!operators.empty())
	{
		outLine.push(operators.top());
		operators.pop();
	}

	RPN = new string[outLine.size()];
	lengthRPN = outLine.size();

	//Переносим в массив для многоразовой работы
	for (int i = outLine.size() - 1; i >= 0; i--)
	{
		RPN[i] = outLine.top();
		outLine.pop();
	}
}

int ReversePolishNot::getPriority(string op)
{
	if (op == "+" or op == "-")
	{
		return 1;
	}
	else if (op == "*" or op == "/")
	{
		return 2;
	}
	else if (op == "^" or op == "sin" or op == "cos" or op == "exp" or op == "ln")
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

void ReversePolishNot::operationPriotity(string op)
{
	if (operators.empty())
	{
		operators.push(op);
	}
	else
	{
		if (getPriority(op) > getPriority(operators.top()))
		{
			operators.push(op);
		}
		else
		{
			while (!operators.empty() and getPriority(op) <= getPriority(operators.top()))
			{
				outLine.push(operators.top());
				operators.pop();
			}
			operators.push(op);
		}
	}
}

ReversePolishNot::ReversePolishNot(string str)
{
	//Добавление пробелов в строку
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' or str[i] == ')' or str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/' or str[i] == '^')
		{
			str.insert(i, " ");
			str.insert(i + 2, " ");
			i += 2;
		}
	}
	this->inputExpression = str.insert(str.length()," ");

	convertToRPN();
}

ReversePolishNot::~ReversePolishNot()
{
	delete[] RPN;
}

double ReversePolishNot::getResult(double* x)
{
	stack <double> result;
	for (int i = 0; i < lengthRPN; i++)
	{
		if (RPN[i] == "+")
		{
			double a = result.top();
			result.pop();
			double b = result.top();
			result.pop();
			result.push(a + b);
		}
		else if (RPN[i] == "-")
		{
			double a = result.top();
			result.pop();
			double b = result.top();
			result.pop();
			result.push(b - a);
		}
		else if (RPN[i] == "*")
		{
			double a = result.top();
			result.pop();
			double b = result.top();
			result.pop();
			result.push(a * b);
		}
		else if (RPN[i] == "/")
		{
			double a = result.top();
			result.pop();
			double b = result.top();
			result.pop();
			result.push(b / a);
		}
		else if (RPN[i] == "^")
		{
			double a = result.top();
			result.pop();
			double b = result.top();
			result.pop();
			result.push(pow(b, a));
		}
		else if (RPN[i] == "sin")
		{
			double a = result.top();
			result.pop();
			result.push(sin(a));
		}
		else if (RPN[i] == "cos")
		{
			double a = result.top();
			result.pop();
			result.push(cos(a));
		}
		else if (RPN[i] == "exp")
		{
			double a = result.top();
			result.pop();
			result.push(exp(a));
		}
		else if (RPN[i] == "ln")
		{
			double a = result.top();
			result.pop();
			result.push(log(a));
		}
		else
		{
			if (isdigit(RPN[i][0]))
			{
				result.push(stod(RPN[i]));
			}
			else
			{
				
				if (RPN[i][0] == 'p' or RPN[i][0] == 'P')//Отделяем х от числа
				{
					result.push(M_PI);
					continue;
				}
				
				//Отделяем х от числа
				string temp = RPN[i];
				temp.erase(0, 1);

				result.push(x[stoi(temp) - 1]);
				
				
				
			}
		}
	}
	return result.top();
}

string ReversePolishNot::printRPN()
{
	stringstream ss;
	for (int i = 0; i < lengthRPN; i++)
	{
		ss << RPN[i] << " ";
	}
	ss << endl;
	return ss.str();
}
