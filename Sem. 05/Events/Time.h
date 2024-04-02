#pragma once

class Time {
private:
	unsigned hours;
	unsigned minutes;
	unsigned seconds;

	unsigned getSecondsFromMidnight() const;
	void setTimeFromSeconds(unsigned seconds);

public:
	Time();
	Time(unsigned hours, unsigned minutes, unsigned seconds);
	explicit Time(unsigned secondsFromMidnight);

	void increment();

	void setHours(unsigned hours);
	void setMinutes(unsigned minutes);
	void setSeconds(unsigned seconds);

	unsigned getHours() const;
	unsigned getMinutes() const;
	unsigned getSeconds() const;

	int compare(const Time& other) const;
	bool isPartyTime() const;
	bool isDinnerTime() const;
	Time getDiff(const Time& other) const;
	void print() const;
};