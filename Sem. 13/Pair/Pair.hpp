#pragma once
#include <iostream>

template<typename T, typename S>
class Pair {
private:
	T first;
	S second;

public:
	Pair() = default;
	Pair(const T& first, const S& second);
	const T& getFirst() const;
	const S& getSecond() const; 
	void setFirst(const T& value);
	void setSecond(const S& value);
};

template<typename T, typename S>
Pair<T, S>::Pair(const T& first, const S& second) : first(first), second(second) {

}

template<typename T, typename S>
const T& Pair<T, S>::getFirst() const {
	return first;
}

template<typename T, typename S>
const S& Pair<T, S>::getSecond() const {
	return second;
}

template<typename T, typename S>
void Pair<T, S>::setFirst(const T& value) {
	first = value;
}

template<typename T, typename S>
void Pair<T, S>::setSecond(const S& value) {
	second = value;
}

template<typename T, typename S>
std::ostream& operator<<(std::ostream& os, const Pair<T, S>& object) {
	os << "(" << object.getFirst() << ", " << object.getSecond() << ")";
	return os;
}