#include <iostream>
#include "UniquePointer.h"

int main() {
	A* a = new A{ 2, 3 };
	UniquePointer ptr1(a);
	std::cout << (*ptr1).a << std::endl;
	UniquePointer ptr2 = std::move(ptr1);
	std::cout << (*ptr2).a << std::endl;
	// std::cout << (*ptr1).a << std::endl;
}