#include <iostream>
#include "ChessBoard/ChessBoard.h"
using namespace std;

int main()
{
	ChessBoard c;

	c.print();

	c.moveFigure(0, 1, 2, 0);

	c.print();
}