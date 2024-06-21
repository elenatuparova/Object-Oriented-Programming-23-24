#include <iostream>
#include "SwapCommand.h"
#include "SortCommand.h"

void printArray(const IntVector& v)
{
	for (size_t i = 0; i < v.getSize(); i++)
	{
		std::cout << v[i] << ' ';
	}

	std::cout << std::endl;
}

class CommandExecutor
{
	Vector<VectorCommand*> waitingExecution; //Queue
	Vector<VectorCommand*> executed; //Stack

public:
	CommandExecutor() = default;
	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;

	void addCommand(VectorCommand* command)
	{
		waitingExecution.pushBack(command);
	}

	void execute()
	{
		if (waitingExecution.empty())
		{
			throw std::exception("...");
		}

		waitingExecution[0]->execute();
		executed.pushBack(waitingExecution.popAt(0));
	}

	void executeAll()
	{
		while (!waitingExecution.empty())
		{
			execute();
		}
	}

	void undo()
	{
		if (executed.empty())
		{
			throw std::exception("...");
		}

		executed[executed.getSize() - 1]->undo();
		delete executed.popBack();
	}

	~CommandExecutor()
	{
		for (size_t i = 0; i < waitingExecution.getSize(); i++)
		{
			delete waitingExecution[i];
		}

		for (size_t i = 0; i < executed.getSize(); i++)
		{
			delete executed[i];
		}
	}
};

struct Factory
{
public:
	static VectorCommand* createCommand(IntVector& v, size_t type)
	{
		if (type == 0)
		{
			return new SortCommand(v);
		}
		else
		{
			size_t from, to;
			std::cin >> from >> to;
			return new SwapCommand(v, from, to);
		}

		throw std::exception("...");
	}
};


int main()
{
	IntVector v;
	for (int i = 9; i >= 0; i--) {
		v.pushBack(i);
	}

	CommandExecutor ce;

	VectorCommand* vc1 = new SwapCommand(v, 4, 5);
	VectorCommand* vc2 = new SortCommand(v);

	ce.addCommand(vc1);
	ce.addCommand(vc2);
	printArray(v);
	ce.execute();
	printArray(v);
	ce.execute();
	printArray(v);
	ce.undo();
	printArray(v);
	ce.undo();
	printArray(v);
}