#pragma once

struct A {
	int a;
	int b;
};

class UniquePointer {
	A* ptr;

	void free();
	void moveFrom(UniquePointer&& other);

public:
	UniquePointer(A* ptr);

	UniquePointer(UniquePointer&& other) noexcept;
	UniquePointer& operator=(UniquePointer&& other) noexcept;

	UniquePointer(const UniquePointer& other) = delete;
	UniquePointer& operator=(const UniquePointer& other) = delete;

	~UniquePointer();

	const A& operator*() const;
	A& operator*();
};
