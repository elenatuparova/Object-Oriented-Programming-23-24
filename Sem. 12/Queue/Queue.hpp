#include <iostream>
#include <exception>
template <typename T>
class MyQueue
{
	T* data;
	size_t capacity;
	size_t size;

	size_t get;
	size_t put;

	void resize();

	void moveFrom(MyQueue<T>&& other);
	void copyFrom(const MyQueue<T>& other);
	void free();
public:
	MyQueue();

	MyQueue(const MyQueue<T>& other);
	MyQueue<T>& operator=(const MyQueue<T>& other);

	MyQueue(MyQueue<T>&& other);
	MyQueue<T>& operator=(MyQueue<T>&& other);

	void push(const T& obj);
	void push(T&& obj);
	void pop();

	const T& peek() const;
	bool isEmpty() const;

	~MyQueue();

};

template <typename T>
MyQueue<T>::MyQueue()
{
	capacity = 4;
	data = new T[capacity];
	size = 0;
	get = put = 0;
}

template <typename T>
void MyQueue<T>::push(const T& obj)
{
	if (size == capacity) {
		resize();
	}
	data[push] = obj;
	(++push) %= capacity;
	size++;
}

template <typename T>
void MyQueue<T>::push(T&& obj)
{
	if (size == capacity) {
		resize();
	}
	data[put] = std::move(obj);
	(++put) %= capacity;
	size++;
}

template <typename T>
bool MyQueue<T>::isEmpty() const
{
	return size == 0;
}


template <typename T>
const T& MyQueue<T>::peek() const
{
	if (isEmpty()) {
		throw std::logic_error("MyQueue::Empty queue!");
	}
	return data[get];
}

template <typename T>
void MyQueue<T>::pop()
{
	if (isEmpty()) {
		throw std::logic_error("MyQueue::Empty queue!");
	}
	(++get) %= capacity;
	size--;
}

template <typename T>
void MyQueue<T>::resize()
{
	T* temp = new T[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		temp[i] = data[get];
		(++get) %= capacity;
	}
	get = 0;
	put = size;
	capacity *= 2;
	delete[] data;
	data = temp;
}


template <typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	get = other.get;
	put = other.put;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
void MyQueue<T>::moveFrom(MyQueue<T>&& other)
{
	size = other.size;
	capacity = other.capacity;
	get = other.get;
	put = other.put;
	data = other.data;
	other.data = nullptr;
	other.size = other.capacity = other.get = other.put = 0;
}

template <typename T>
void MyQueue<T>::free()
{
	delete[] data;
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other)
{
	copyFrom(other);

}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}


template <typename T>
MyQueue<T>::~MyQueue()
{
	free();
}