#pragma once
#include <string>
#include "string_parser.h"

class Calculator
{
public:
	Calculator() = default;
	void launch();
	void pictureAnswer();

private:
	StringParser stringParser_;
	std::string expression_;
	float answer_;
};

