#include <iostream>
#include <fstream>

bool copyFile(const char* sourceFile, const char* destFile)
{
	std::ifstream sourceStream(sourceFile);

	if (!sourceStream.is_open()) {
		return false;
	}
		
	std::ofstream destStream(destFile);
	if (!destStream.is_open()) {
		sourceStream.close();
		return false;
	}

	while (!sourceStream.eof())
	{
		char buff[1024];
		sourceStream.getline(buff, 1024);
		destStream << buff << std::endl;
	}
	sourceStream.close();
	destStream.close();
}
int main()
{
	std::cout << copyFile("file1.txt", "file2.txt");
}