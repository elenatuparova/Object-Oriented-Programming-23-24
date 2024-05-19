#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
	double radius;
public:
	Circle(int x, int y, double radius);

	Shape* clone() const override;

	double getArea() const override;
	double getPer() const override;
	bool isPointIn(int x, int y) const override;

	virtual bool intersect(const Shape*) const override;
	virtual bool intersectWithCircle(const Circle*) const override;
	virtual bool intersectWithTriangle(const Triangle*) const override;
	virtual bool intersectWithRectangle(const Rectangle*) const override;
};