#include "UniquePointer.h"
#include <iostream>

void UniquePointer::free()
{
	delete ptr;
	ptr = nullptr;
}

void UniquePointer::moveFrom(UniquePointer&& other)
{
	ptr = other.ptr;
	other.ptr = nullptr;
}

UniquePointer::UniquePointer(A* ptr) : ptr(ptr)
{

}

UniquePointer::UniquePointer(UniquePointer&& other) noexcept
{
	moveFrom(std::move(other));
}

UniquePointer& UniquePointer::operator=(UniquePointer&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

UniquePointer::~UniquePointer()
{
	free();
}

const A& UniquePointer::operator*() const
{
	return *ptr;
}

A& UniquePointer::operator*()
{
	return *ptr;
}
