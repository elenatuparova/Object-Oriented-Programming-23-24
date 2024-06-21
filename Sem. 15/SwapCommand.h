#pragma once
#include "VectorCommand.h"


class SwapCommand : public VectorCommand
{
	size_t from, to;
public:
	SwapCommand(IntVector& v, size_t from, size_t to);

	void execute() override;

	void undo() override;
};

