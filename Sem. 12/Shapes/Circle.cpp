#include "Circle.h"
#include <iostream>

namespace {
	const double PI = 3.1415;
}

Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius) {
	setPoint(0, x, y);
}

double Circle::getArea() const {
	return PI * radius * radius;
}

double Circle::getPer() const {
	return 2 * PI * radius;
}

bool Circle::isPointIn(int x, int y) const {
	Shape::Point point(x, y);
	return getDistance(point, getPoint(0)) <= radius;
}

Shape* Circle::clone() const {
	return new Circle(*this);
}

bool Circle::intersect(const Shape* other) const
{
	return other->intersectWithCircle(this);
}

bool Circle::intersectWithCircle(const Circle* other) const
{
	std::cout << "Intersect circle with circle";
	return true;
}

bool Circle::intersectWithTriangle(const Triangle* other) const
{
	std::cout << "Intersect circle with triangle";
	return true;
}

bool Circle::intersectWithRectangle(const Rectangle* other) const
{
	std::cout << "Intersect circle with rectangle";
	return true;
}