#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4) {
	setPoint(0, x1, y1);
	setPoint(1, x1, y3);
	setPoint(2, x3, y1);
	setPoint(3, x3, y3);
}

double Rectangle::getArea() const {
	const Shape::Point& p0 = getPoint(0);
	const Shape::Point& p1 = getPoint(1);
	const Shape::Point& p3 = getPoint(3);

	return getDistance(p0, p1) * getDistance(p1, p3);
}

double Rectangle::getPer() const {
	const Shape::Point& p0 = getPoint(0);
	const Shape::Point& p1 = getPoint(1);
	const Shape::Point& p3 = getPoint(3);

	return 2 * (getDistance(p0, p1) + getDistance(p1, p3));
}

bool Rectangle::isPointIn(int x, int y) const {
	return x >= getPoint(0).x && y >= getPoint(1).x &&
		y <= getPoint(0).y && y >= getPoint(2).y;
}

Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}

bool Rectangle::intersect(const Shape* other) const
{
	return other->intersectWithRectangle(this);
}

bool Rectangle::intersectWithCircle(const Circle* other) const
{
	std::cout << "Intersect rectangle with circle";
	return true;
}

bool Rectangle::intersectWithTriangle(const Triangle* other) const
{
	std::cout << "Intersect rectangle with triangle";
	return true;
}

bool Rectangle::intersectWithRectangle(const Rectangle* other) const
{
	std::cout << "Intersect rectangle with rectangle";
	return true;
}