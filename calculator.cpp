#include "calculator.h"
#include <iostream>

void Calculator::launch() 
{
	std::cin >> Calculator::expression_;
}

void Calculator::pictureAnswer() 
{
	std::cout << Calculator::answer_;
}

