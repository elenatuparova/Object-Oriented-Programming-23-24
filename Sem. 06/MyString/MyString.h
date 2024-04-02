#pragma once
#include <iostream>

class MyString 
{
private:
	char* data;
	size_t size;

	void copyFrom(const MyString& other);
	void free();

public:

	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	size_t length() const;
	const char* c_str() const;
};
