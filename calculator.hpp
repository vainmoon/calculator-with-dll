#pragma once
#include "coreCalculator.hpp"

class Calculator
{
public:
	Calculator();
	void launch();
	void pictureAnswer();

private:
	CoreCalculator coreCalculator_;
	std::string expression_;
	double answer_;
};

