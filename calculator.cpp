#include <iostream>
#include "calculator.hpp"

Calculator::Calculator() : answer_(), expression_()
{
	CoreCalculator coreCalculator_();
}

void Calculator::launch() 
{
	getline(std::cin, expression_);
	answer_ = coreCalculator_.interpret(expression_);
}

void Calculator::pictureAnswer() 
{
	std::cout << Calculator::answer_;
}

