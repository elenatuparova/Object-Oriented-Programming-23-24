#include <iostream>
#include <fstream>

namespace FileNamesConstants {
	constexpr char INPUT_FILE_NAME[] = "inputFileNumbers.dat";
	constexpr char EVEN_FILE_NAME[] = "evenNumbers.dat";
	constexpr char ODD_FILE_NAME[] = "oddNumbers.dat";
}

struct FileContents {
	int* contents;
	size_t contentsSize;
};

size_t getFileSize(std::ifstream& ifs) {
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currentPosition, std::ios::beg);
	return size;
}

FileContents readDataFromFile(std::ifstream& ifs) {
	size_t fileSize = getFileSize(ifs);
	FileContents contents;
	contents.contentsSize = fileSize / sizeof(int);
	contents.contents = new int[contents.contentsSize];
	return contents;
}

void freeFileContents(FileContents& fileContents) {
	delete[] fileContents.contents;
	fileContents.contentsSize = 0;
}

size_t countEvenNumbers(const int* numbers, size_t size) {
	size_t evenCounter = 0;
	for (size_t i = 0; i < size; i++) {
		if (!(numbers[i] & 1)) {
			evenCounter++;
		}
	}
	return evenCounter;
}

void fillEvenOddArrays(const FileContents& fileContent, int* even, int* odd, size_t evenCount, size_t oddCount) {
	size_t evenIndex = 0;
	size_t oddIndex = 0;
	for (size_t i = 0; i < fileContent.contentsSize; i++) {
		if (!(fileContent.contents[i] & 1)) {
			even[evenIndex++] = fileContent.contents[i];
		}
		else {
			odd[oddIndex++] = fileContent.contents[i];
		}
	}
}

void divideOddAndEven(const char* sourceFile, const char* evenFile, const char* oddFile) {
	std::ifstream input(sourceFile, std::ios::binary);
	if (!input.is_open()) {
		std::cout << "Error while opening input file." << std::endl;
		return;
	}

	std::ofstream even(evenFile, std::ios::binary);
	if (!even.is_open()) {
		std::cout << "Error while opening output file for even numbers." << std::endl;
		input.close();
		return;
	}

	std::ofstream odd(oddFile, std::ios::binary);
	if (!odd.is_open()) {
		std::cout << "Error while opening output file for odd numbers." << std::endl;
		input.close();
		even.close();
		return;
	}

	FileContents inputFileContents = readDataFromFile(input);
	input.close();

	size_t evenCount = countEvenNumbers(inputFileContents.contents, inputFileContents.contentsSize);
	size_t oddCount = inputFileContents.contentsSize - evenCount;

	int* evenNumbers = new int[evenCount];
	int* oddNumbers = new int[oddCount];

	fillEvenOddArrays(inputFileContents, evenNumbers, oddNumbers, evenCount, oddCount);

	even.write((const char*)evenNumbers, evenCount * sizeof(int));
	odd.write((const char*)oddNumbers, oddCount * sizeof(int));

	delete[] evenNumbers;
	delete[] oddNumbers;

	freeFileContents(inputFileContents);
	even.close();
	odd.close();
}

int main() {
	divideOddAndEven(
		FileNamesConstants::INPUT_FILE_NAME, 
		FileNamesConstants::EVEN_FILE_NAME, 
		FileNamesConstants::ODD_FILE_NAME
	);
	return 0;
}