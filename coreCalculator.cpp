#include <stack>
#include "coreCalculator.hpp"

std::vector<std::string> CoreCalculator::tokenize(const std::string& expression)
{
	std::vector <std::string> tokens;

	std::string num;
	std::string op;

	for (char symbol : expression) 
	{
		if (isdigit(symbol) || symbol == '.')
		{
			if (!op.empty()) 
			{
				tokens.push_back(op);
				op.clear();
			}

			num += symbol;
		}
		else if (!isspace(symbol)) 
		{
			if (!num.empty()) 
			{
				tokens.push_back(num);
				num.clear();
			}
			if (symbol == '(' || symbol == ')')
			{
				if (!op.empty())
				{
					tokens.push_back(op);
					op.clear();
				}
				tokens.push_back(std::string(1, symbol));
			}
			op += symbol;
		}
	}

	if (!op.empty()) { tokens.push_back(op); }
	else if (!num.empty()) { tokens.push_back(num); }

	return tokens;
}

std::vector<std::string> CoreCalculator::parse(const std::vector<std::string>& tokens) 
{
	std::stack <std::string> operationStack;
	std::vector <std::string> postfix;

	for (std::string token : tokens) 
	{
		if (isdigit(token[0])) 
		{
			postfix.push_back(token);
		}
		else 
		{
			while ((!operationStack.empty()) && (getOperationPriority(token) <= getOperationPriority(operationStack.top())))
			{
				postfix.push_back(operationStack.top());
				operationStack.pop();
			}
			operationStack.push(token);
		}
	}
	while (!operationStack.empty()) 
	{
		postfix.push_back(operationStack.top());
		operationStack.pop();
	}
	return postfix;
}

double CoreCalculator::calculate(const std::vector<std::string>& postfix)
{
	std::stack <double> calculationStack;
	for (std::string token : postfix) 
	{
		if (isdigit(token[0]))
		{
			calculationStack.push(std::stod(token));
		}
		else
		{
			double secondArgument = calculationStack.top();
			calculationStack.pop();
			double firstArgument = calculationStack.top();
			calculationStack.pop();
			calculationStack.push(operate(token, firstArgument, secondArgument));
		}
	}
	return calculationStack.top();
}

double CoreCalculator::interpret(const std::string& expression)
{
	return calculate(parse(tokenize(expression)));
}

double CoreCalculator::operate(const std::string& operation, double firstArgument, double secondArgument) 
{
	if (operation == "+") return firstArgument + secondArgument;
	else if (operation == "-") return firstArgument - secondArgument;
	else if (operation == "*") return firstArgument * secondArgument;
	else if (operation == "/") return firstArgument / secondArgument;
}

int CoreCalculator::getOperationPriority(const std::string& operation)
{
	if (operation == "+" || operation == "-") { return 1; }
	else if (operation == "*" || operation == "/") { return 2; }
}