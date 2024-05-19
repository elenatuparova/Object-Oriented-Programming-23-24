#pragma once
#include <exception>

template<typename T>
class Optional {
private:
	T* value = nullptr;

public:
	Optional() = default;
	Optional(const T& value);
	Optional(const Optional<T>& other);
	Optional(Optional<T>&& other) noexcept;

	Optional<T>& operator=(const Optional<T>& other);
	Optional<T>& operator=(Optional<T>&& other) noexcept;

	~Optional();

	bool hasValue() const;
	const T& getValue() const;
	void setValue(const T& newValue);
	void setValue(T&& newValue);
	void clear();

private:
	void copyFrom(const Optional& other);
	void moveFrom(Optional<T>&& other);
	void free();
};

template<typename T>
Optional<T>::Optional(const T& value) {
	this->value = new T(value);
}

template<typename T>
Optional<T>::Optional(const Optional<T>& other) {
	copyFrom(other);
}

template<typename T>
Optional<T>::Optional(Optional<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Optional<T>& Optional<T>::operator=(Optional<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
Optional<T>::~Optional() {
	free();
}

template<typename T>
bool Optional<T>::hasValue() const {
	// TODO
}

template<typename T>
const T& Optional<T>::getValue() const {
	// TODO
}

template<typename T>
void Optional<T>::setValue(const T& newValue) {
	// TODO
}

template<typename T>
void Optional<T>::setValue(T&& newValue) {
	// TODO
}

template<typename T>
void Optional<T>::clear() {
	// TODO
}

template<typename T>
void Optional<T>::copyFrom(const Optional<T>& other) {
	// TODO
}

template<typename T>
void Optional<T>::moveFrom(Optional<T>&& other) {
	// TODO
}

template<typename T>
void Optional<T>::free() {
	// TODO
}