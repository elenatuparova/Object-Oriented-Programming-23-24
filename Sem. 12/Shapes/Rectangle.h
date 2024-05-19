#pragma once

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(int x1, int y1, int x3, int y3);

	Shape* clone() const override;

	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;

	virtual bool intersect(const Shape*) const override;
	virtual bool intersectWithCircle(const Circle*) const override;
	virtual bool intersectWithTriangle(const Triangle*) const override;
	virtual bool intersectWithRectangle(const Rectangle*) const override;
};
