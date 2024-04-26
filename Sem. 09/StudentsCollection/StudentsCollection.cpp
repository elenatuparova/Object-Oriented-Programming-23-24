#include "StudentsCollection.h"

void StudentsCollection::copyFrom(const StudentsCollection& other)
{
}

void StudentsCollection::moveFrom(StudentsCollection&& other)
{
	students = other.students;
	count = other.count;
	capacity = other.capacity;
	size = other.size;
	firstFreeIndex = other.firstFreeIndex;

	other.students = nullptr;
	other.count = other.capacity = other.size = other.firstFreeIndex = 0;
}

void StudentsCollection::goToNextFreeIndex()
{
}

StudentsCollection::StudentsCollection(StudentsCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentsCollection& StudentsCollection::operator=(StudentsCollection&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void StudentsCollection::addAtFirstFree(const Student& student)
{
	if (count == capacity) {
		resize(capacity * 2);
	}

	students[firstFreeIndex] = new Student(student);
	if (firstFreeIndex > size) {
		size++;
	}
	goToNextFreeIndex();
	count++;

	if (firstFreeIndex > size) {
		size++;
	}
}

void StudentsCollection::addAtFirstFree(Student&& student)
{
	if (count == capacity) {
		resize(capacity * 2);
	}

	students[firstFreeIndex] = new Student(std::move(student));
	if (firstFreeIndex > size) {
		size++;
	}
	goToNextFreeIndex();
	count++;

	if (firstFreeIndex > size) {
		size++;
	}
}

void StudentsCollection::setAtIdx(const Student& student, size_t idx)
{
}

void StudentsCollection::setAtIdx(Student&& student, size_t idx)
{
}

void StudentsCollection::removeAtIdx(size_t idx)
{
}
