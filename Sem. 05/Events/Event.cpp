#include "Event.h"
#include <string>
#pragma warning(disable:4996)

Event::Event() : Event("", 1, 1, 1, 0, 0, 0, 0, 0, 0) {};

Event::Event(const char* _name, const BulgarianDate& _date, const Time& _startTime, const Time& _endTime) : date(_date), startTime(_startTime), endTime(_endTime) {
	setName(_name);
	validateTime();
}

Event::Event(const char* _name, int day, int month, int year,
	unsigned startHour, unsigned startMinutes, unsigned startSeconds,
	unsigned endHour, unsigned endMinutes, unsigned endSeconds) : date(day, month, year), startTime(startHour, startMinutes, startSeconds), endTime(endHour, endMinutes, endSeconds) {
	setName(_name);
	validateTime();
}

void Event::setName(const char* _name) {
	if (strlen(_name) > 20) {
		return;
	}
	strcpy(name, _name);
}

const char* Event::getName() const {
	return name;
}

const BulgarianDate& Event::getDate() const {
	return date;
}

const Time& Event::getStartTime() const {
	return startTime;
}

const Time& Event::getEndTime() const {
	return endTime;
}

void Event::validateTime() {
	if (startTime.compare(endTime) >= 1) {
		std::swap(startTime, endTime);
	}
}