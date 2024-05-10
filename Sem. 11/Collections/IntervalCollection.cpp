#include "IntervalCollection.h"
#include <iostream>

IntervalCollection::IntervalCollection(int start, int end) 
{
	if (start > end) {
		std::swap(start, end);
	}
	this->start = start;
	this->end = end;

	data = new int[end - start + 1] {0};
}


unsigned IntervalCollection::intervalLength() const
{
	return end - start + 1;
}

void IntervalCollection::add(int elem)
{
	if (elem < start || elem > end) {
		throw std::exception("Element out of interval");
	}
	data[elem - start]++;
}

void IntervalCollection::remove(int elem)
{
	if (elem < start || elem > end) {
		throw std::exception("Element out of interval");
	}
	if (data[elem - start] == 0) {
		return;
	}
	data[elem - start]--;
}

unsigned IntervalCollection::count(int elem) const
{
	if (elem < start || elem > end) {
		throw std::exception("Element out of interval");
	}
	return data[elem - start];
}

bool IntervalCollection::contains(int elem) const
{
	if (elem < start || elem > end) {
		throw std::exception("Element out of interval");
	}
	return data[elem - start] != 0;
}