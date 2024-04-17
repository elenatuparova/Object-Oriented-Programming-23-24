#include <iostream>

class MapOfNumbers {
	static constexpr int MAX_SIZE = 150;
	int numbers[MAX_SIZE];
	unsigned currentSize = 0;

public:
	MapOfNumbers() {
		for (int i = 0; i < MAX_SIZE; i++) {
			numbers[i] = -1;
		}
	}

	void insert(unsigned key, int value) {
		if (key >= MAX_SIZE) {
			throw std::out_of_range("Key out of range");
		}
		numbers[key] = value;
		currentSize++;
	}
	int get(unsigned key) const {
		if (key >= MAX_SIZE || numbers[key] == -1) {
			throw std::out_of_range("Key out of range");
		}
		return numbers[key];
	}
	bool contains(unsigned key) const {
		if (key >= MAX_SIZE) {
			throw std::out_of_range("Key out of range");
		}
		return numbers[key] != -1;
	}
	bool isEmpty() const {
		return currentSize == 0;
	}
};

unsigned fib(unsigned n) {
	static MapOfNumbers cache;

	if (cache.isEmpty()) {
		cache.insert(1, 1);
		cache.insert(2, 1);
	}

	if (cache.contains(n)) {
		return cache.get(n);
	}

	cache.insert(n, fib(n - 1) + fib(n - 2));
	return cache.get(n);
}