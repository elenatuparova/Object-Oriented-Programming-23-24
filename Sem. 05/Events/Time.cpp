#include "Time.h"
#include <iostream>

Time::Time() : hours(0), minutes(0), seconds(0) {};

Time::Time(unsigned hours, unsigned minutes, unsigned seconds) {
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

Time::Time(unsigned secondsFromMidnight) {
	setTimeFromSeconds(secondsFromMidnight);
}

void Time::increment() {
	unsigned secondsFromMidnight = getSecondsFromMidnight();
	secondsFromMidnight++;
	setTimeFromSeconds(secondsFromMidnight);
}

void Time::setHours(unsigned hours) {
	if (hours <= 23) {
		this->hours = hours;
	}
	else {
		this->hours = 0;
	}
}

void Time::setMinutes(unsigned minutes) {
	if (minutes <= 59) {
		this->minutes = minutes;
	}
	else {
		this->minutes = 0;
	}
}

void Time::setSeconds(unsigned seconds) {
	if (seconds <= 59) {
		this->seconds = seconds;
	}
	else {
		this->seconds = 0;
	}
}

unsigned Time::getHours() const {
	return hours;
}

unsigned Time::getMinutes() const {
	return minutes;
}

unsigned Time::getSeconds() const {
	return seconds;
}

int Time::compare(const Time& other) const {
	unsigned mySecondsFromMidnight = getSecondsFromMidnight();
	unsigned otherSecondsFromMidnight = other.getSecondsFromMidnight();

	return mySecondsFromMidnight - otherSecondsFromMidnight;
}

bool Time::isPartyTime() const {
	Time begin(23, 0, 0);
	Time end(6, 0, 0);

	return compare(begin) > 0 || compare(end) < 0;
}

bool Time::isDinnerTime() const {
	Time begin(20, 30, 0);
	Time end(22, 0, 0);

	return compare(begin) > 0 && compare(end) < 0;
}

Time Time::getDiff(const Time& other) const {
	unsigned diffSeconds = fabs(getSecondsFromMidnight() - other.getSecondsFromMidnight());
	return Time(diffSeconds);
}

void Time::print() const {
	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}

unsigned Time::getSecondsFromMidnight() const {
	return hours * 3600 + minutes * 60 + seconds;
}

void Time::setTimeFromSeconds(unsigned seconds) {
	if (seconds >= 24 * 3600) {
		hours = 0;
		minutes = 0;
		this->seconds = 0;
		return;
	}
	hours = seconds / 3600;
	seconds %= 3600;
	minutes = seconds / 60;
	this->seconds = seconds % 60;
}