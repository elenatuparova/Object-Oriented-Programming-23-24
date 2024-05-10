#include "SortedCollection.h"

int SortedCollection::lowerBound(int elem) const
{
	int left = 0;
	int right = size - 1;

	int indexToReturn = size;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid] < elem)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			indexToReturn = mid;
		}
	}

	return indexToReturn;
}

int SortedCollection::upperBound(int elem) const
{
	int left = 0;
	int right = size - 1;

	int indexToReturn = size;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid] <= elem)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			indexToReturn = mid;
		}
	}

	return indexToReturn;
}

void SortedCollection::add(int elem)
{
	if (size == capacity)
	{
		resize(2 * size);
	}

	int idx = size;
	while (idx > 0 && data[idx] > elem) {
		data[idx] = data[idx - 1];
		idx--;
	}
	data[idx] = elem;
	size++;
}

void SortedCollection::remove(int elem)
{
	int idx = upperBound(elem);
	if (idx == size) {
		return;
	}
	for (int i = idx; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

unsigned SortedCollection::count(int elem) const
{
	int first = lowerBound(elem);
	if (first == size) {
		return 0;
	}
	int last = upperBound(elem);
	return last - first + 1;
}

bool SortedCollection::contains(int elem) const
{
	return lowerBound(elem) != size;
}