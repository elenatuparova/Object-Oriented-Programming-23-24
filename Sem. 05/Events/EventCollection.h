#pragma once

#include "Event.h"

class EventCollection
{
	Event events[20];
	unsigned count = 0;

public:
	EventCollection() = default;
	bool addEvent(const Event& event);
	bool removeEventByIndex(unsigned idx);
	bool removeEventByName(const char* name);
	int getEventIndexByName(const char* name) const;
	void print() const;
	EventCollection getEventsOnDate(const BulgarianDate& date) const;
};