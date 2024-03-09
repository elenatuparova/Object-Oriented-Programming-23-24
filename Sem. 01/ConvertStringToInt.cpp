#include <iostream>

enum class ExitCode {
	OK, 
	NullptrProvided,
	EmptyString,
	InvalidSymbol
};

void printExitCode(const ExitCode& code) {
	// TODO 
}

struct ConversionResult {
	ExitCode code;
	unsigned int number;
};

bool isDigit(char ch) {
	return (ch >= '0' && ch <= '9');
}

unsigned charToInt(char ch) {
	return ch - '0';
}

ConversionResult convertStringToNumber(const char* str) {
	if (!str) {
		return { ExitCode::NullptrProvided, 0 };
	}

	if (!(*str)) {
		return { ExitCode::EmptyString, 0 };
	}

	unsigned int number = 0;
	while (*str) {
		if (!isDigit(*str)) {
			return { ExitCode::InvalidSymbol, 0 };
		}
		number *= 10;
		number += charToInt(*str);
		str++;
	}

	return { ExitCode::OK, number };
}


int main()
{
	const char* myString = "12345e";
	ConversionResult result = convertStringToNumber(myString);

	if (result.code == ExitCode::OK) {
		std::cout << result.number << std::endl;
	}
	else {
		std::cout << "Error! Exit code: " << (int)result.code << std::endl;
	}
	
	return 0;
}