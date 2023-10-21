#pragma once
#include <string>
#include <queue>
#include <vector>

class CoreCalculator
{
public:
	CoreCalculator() = default;

	std::vector<std::string> tokenize(const std::string& expression);

	std::vector<std::string> parse(const std::vector<std::string>& tokens);

	int getOperationPriority(const std::string& operation);
	
	double calculate(const std::vector<std::string>& postfix);

	double operate(const std::string& operation, double firstArgument, double secondArgument);

	double interpret(const std::string& expression);
};

