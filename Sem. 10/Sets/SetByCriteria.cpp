#include "SetByCriteria.h"

void SetByCriteria::setNumbers() {
	for (unsigned i = 0; i < getMax(); i++) {
		add(i);
	}
}

SetByCriteria::SetByCriteria(unsigned max, bool (*pred) (unsigned n)) : BitSet(max) {
	if (pred != nullptr) {
		this->pred = pred;
	}
	else {
		// todo!
	}

	setNumbers();
}

void SetByCriteria::add(unsigned n) {
	if (pred(n)) {
		BitSet::add(n);
	}
}

void SetByCriteria::remove(unsigned n) {
	BitSet::remove(n);
}

bool SetByCriteria::contains(unsigned n) const {
	return BitSet::contains(n);
}

void SetByCriteria::setPredicate(bool (*pred) (unsigned n)) {
	this->pred = pred;
	BitSet::clear();
	setNumbers();
}