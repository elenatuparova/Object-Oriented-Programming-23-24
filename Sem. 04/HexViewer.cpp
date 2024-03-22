#include <iostream>
#include <fstream>
#include <iomanip>

struct HexViewerFile {
	unsigned char* content;
	size_t size;
};

size_t getFileSize(std::ifstream& file)
{
	size_t currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

HexViewerFile readFile(const char* filename) {
	std::ifstream ifs(filename, std::ios::binary);
	HexViewerFile file;
	if (!ifs.is_open()) {
		file.content = nullptr;
		file.size = 0;
		return file;
	}

	file.size = getFileSize(ifs);
	file.content = new unsigned char[file.size];
	ifs.read((char*)file.content, file.size);
	ifs.close();
	return file;
}

bool isLetter(char c) {
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

void print(const HexViewerFile& file) {
	for (size_t i = 0; i < file.size; i++) {
		std::cout << std::hex << std::setw(2) << (int)file.content[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < file.size; i++) {
		if (isLetter(file.content[i])) {
			std::cout << std::setw(2) << file.content[i] << " ";
		}
		else {
			std::cout << std::setw(2) << ".. ";
		}
	}
	std::cout << std::endl;
}

// TODO implement byte modification using fstream
void modifyByte(HexViewerFile& file, unsigned index, unsigned char value) {
	if (index >= file.size) {
		return;
	}
	file.content[index] = value;
}

// TODO implement writing to file
void saveToFile(const HexViewerFile& file, const char* filename);


int main()
{
	HexViewerFile file = readFile("myFile.dat");
	print(file);
	modifyByte(file, 2, 'r');
	print(file);
	return 0;
}