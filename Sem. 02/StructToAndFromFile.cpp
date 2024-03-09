#include <iostream>
#include <fstream>

enum class Major {
	SE,
	CS,
	IS,
	I
};

struct Student {
	char name[50];
	unsigned age;
	Major major;
};


void saveStudentToFile(std::ofstream& ofs, const Student& student) {
	ofs << student.name << std::endl;
	ofs << student.age << std::endl;
	ofs << (int)student.major << std::endl;
}

bool writeStudentArrayToFile(const char* filename, const Student* students, size_t size) {
	std::ofstream ofs(filename);
	if (!ofs.is_open()) {
		return false;
	}
	ofs << size << std::endl;
	for (int i = 0; i < size; i++) {
		saveStudentToFile(ofs, students[i]);
	}
	ofs.close();
}

void readStudentFromFile(std::ifstream& ifs, Student& student) {
	ifs.getline(student.name, 50);
	ifs >> student.age;
	ifs.ignore();
	int majorAsInt;
	ifs >> majorAsInt;
	student.major = (Major)majorAsInt;
	ifs.ignore();
}

Student* readStudentArrayFromFile(const char* filename, size_t& size) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		return nullptr;
	}

	ifs >> size;
	ifs.ignore();
	Student* students = new Student[size];
	for (int i = 0; i < size; i++) {
		readStudentFromFile(ifs, students[i]);
	}
	ifs.close();
	return students; // TODO clean memory in main!!
}

int main() {
	// example for writing to file
	Student studentsToWrite[3] = {
		"Ivan Petrov", 19, Major::SE,
		"Antonia Georgieva", 20, Major::CS,
		"Petar Dimitrov", 23, Major::SE
	};

	writeStudentArrayToFile("students.txt", studentsToWrite, 3);

	// example for reading from file
	size_t studentsCount = 0;
	Student* studentsToRead = readStudentArrayFromFile("students.txt", studentsCount);
	// do something with array
	delete[] studentsToRead;

	return 0;
}