#pragma once
#include <iostream>

class MyString
{
private:
	char* data;
	unsigned size;
	unsigned capacity;

	void copyFrom(const MyString& other);
	void free();
	void resize();

	explicit MyString(unsigned capacity);

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	unsigned length() const;
	const char* c_str() const;
	MyString& concat(const MyString& other);

	MyString& operator+=(const MyString& other);
	MyString& operator+=(char ch);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);

	char& operator[](unsigned ind);
	char operator[](unsigned ind) const;

	friend std::istream& operator>>(std::istream& is, MyString& lhs);
};

std::ostream& operator<<(std::ostream& os, const MyString& lhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);

unsigned nextPowerOfTwo(unsigned n);