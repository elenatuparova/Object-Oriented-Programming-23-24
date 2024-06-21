#include "SortCommand.h"

SortCommand::SortCommand(IntVector& v) :VectorCommand(v)
{

}

void SortCommand::execute()
{
	if (snapshot)
	{
		delete snapshot;
	}

	snapshot = new IntVector(v);

	for (size_t i = 0; i < v.getSize() - 1; i++)
	{
		size_t targetIndex = i;
		for (size_t j = i + 1; j < v.getSize(); j++)
		{
			if (v[j] < v[targetIndex])
			{
				targetIndex = j;
			}
		}

		if (targetIndex != i)
		{
			std::swap(v[targetIndex], v[i]);
		}
	}
}

void SortCommand::undo()
{
	if (snapshot)
	{
		v = std::move(*snapshot);
		delete snapshot;
		snapshot = nullptr;
	}
}
