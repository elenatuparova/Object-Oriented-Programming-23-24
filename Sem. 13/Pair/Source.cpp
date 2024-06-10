#include "Pair.hpp"
#include <iostream>

int main() {
	Pair<int, int> p1(4, 5);
	Pair<int, double> p2(3, 3.14);
	Pair<int, Pair<int, int>> p3(4, p1);
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
}