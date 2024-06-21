#pragma once
#include "VectorCommand.h"

class SortCommand : public VectorCommand
{
	IntVector* snapshot = nullptr;

public:
	SortCommand(IntVector& v);

	void execute() override;

	void undo() override;
};

