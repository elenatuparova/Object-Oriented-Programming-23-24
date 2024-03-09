#include <iostream> 
#include <fstream>

constexpr int BUFFER_SIZE = 100;

int main() {
	std::ifstream myInputFile("SelfPrinting.cpp");
	if (!myInputFile.is_open()) {
		std::cout << "Error while opening file.";
		return 1;
	}

	char buffer[BUFFER_SIZE];
	while (!myInputFile.eof()) {
		myInputFile.getline(buffer, BUFFER_SIZE);
		std::cout << buffer << std::endl;
	}

	myInputFile.close();
	return 0;
}