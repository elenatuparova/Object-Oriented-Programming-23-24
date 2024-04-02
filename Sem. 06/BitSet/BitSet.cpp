#include "BitSet.h"
#include <iostream>

void BitSet::copyFrom(const BitSet& other)
{
	data = new unsigned char[(other.maxNumber + 1) / 8 + 1];
	for (int i = 0; i < (other.maxNumber + 1) / 8 + 1; i++) {
		data[i] = other.data[i];
	}
	maxNumber = other.maxNumber;
}

void BitSet::free()
{
	delete[] data;
	data = nullptr;
	maxNumber = 0;
}

unsigned BitSet::getBucketIndex(unsigned n) const
{
	return n / 8;
}

unsigned BitSet::getBucketCount() const
{
	return (maxNumber + 1) / 8 + 1;
}

unsigned char BitSet::getMask(unsigned n) const
{
	unsigned indexInBucket = n % 8;

	unsigned char mask = 1;
	return mask << (7 - indexInBucket);
}

BitSet::BitSet() : BitSet(100)
{
}

BitSet::BitSet(unsigned max)
{
	data = new unsigned char[max / 8 + 1];
	maxNumber = max - 1;
}

BitSet::BitSet(const BitSet& other)
{
	copyFrom(other);
}

BitSet& BitSet::operator=(const BitSet& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

BitSet::~BitSet()
{
	free();
}

bool BitSet::add(unsigned n)
{
	if (n > maxNumber || contains(n)) {
		return false;
	}

	unsigned bucketIndex = getBucketIndex(n);
	unsigned mask = getMask(n);

	data[bucketIndex] |= mask;
	return true;
}

bool BitSet::remove(unsigned n)
{
	if (n > maxNumber || contains(n)) {
		return false;
	}

	unsigned bucketIndex = getBucketIndex(n);
	unsigned mask = getMask(n);

	data[bucketIndex] ^= mask;
	return true;
}

bool BitSet::contains(unsigned n) const
{
	unsigned bucketIndex = getBucketIndex(n);
	unsigned mask = getMask(n);

	return data[bucketIndex] & mask;
}

void BitSet::print() const
{
	for (int i = 0; i < maxNumber; i++) {
		if (contains(i)) {
			std::cout << i << std::endl;
		}
	}
}
