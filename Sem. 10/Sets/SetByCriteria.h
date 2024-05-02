#pragma once
#include "BitSet.h"

class SetByCriteria : public BitSet
{
private:
	bool (*pred) (unsigned n);
	void setNumbers();

public:
	SetByCriteria(unsigned max, bool (*pred) (unsigned n));

	void add(unsigned n);
	bool contains(unsigned n) const;
	void remove(unsigned n);

	void setPredicate(bool (*pred) (unsigned n));
};

