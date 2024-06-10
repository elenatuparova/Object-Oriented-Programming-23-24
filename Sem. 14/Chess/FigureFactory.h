#pragma once
#include "Figure.h"
#include "ConfigEnum.h"

class FigureFactory
{
public:
	static Figure* createFigure(bool isWhite, FigureType); //enum
};