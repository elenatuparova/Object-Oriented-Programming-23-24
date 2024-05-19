#pragma once

#include "Shape.h"

class Triangle : public Shape {
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

	Shape* clone() const override;

	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;

	virtual bool intersect(const Shape*) const override;
	virtual bool intersectWithCircle(const Circle*) const override;
	virtual bool intersectWithTriangle(const Triangle*) const override;
	virtual bool intersectWithRectangle(const Rectangle*) const override;
};
