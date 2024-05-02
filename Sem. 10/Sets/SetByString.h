#pragma once
#include "BitSet.h"

class SetByString : private BitSet
{
	char* str;

	void free();
	void copyFrom(const SetByString& other);
	void moveFrom(SetByString&& other);

	void setNumbersFromString();

public:
	SetByString(unsigned n, const char* data);
	SetByString(const SetByString& other);
	SetByString(SetByString&& other) noexcept;

	SetByString& operator=(const SetByString& other);
	SetByString& operator=(SetByString&& other) noexcept;

	~SetByString();

	void print() const;
	void setText(const char* newStr);
	void setAt(unsigned idx, char ch);
};
