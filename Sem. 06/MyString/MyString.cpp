#include "MyString.h"

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	data = new char[size + 1];
	strcpy(data, other.data);
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* data)
{
	size = strlen(data);
	this->data = new char[size + 1];
	strcpy(this->data, data);
}


MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return size;
}

const char* MyString::c_str() const
{
	return data;
}