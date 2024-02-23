#include <iostream>
#include <assert.h>

struct Rational {
	int nominator;
	int denominator;
};

bool isValid(const Rational& rat) {
	return rat.denominator != 0;
}

void printRational(const Rational& rat) {
	assert(isValid(rat));
	std::cout << rat.nominator << "/" << rat.denominator << std::endl;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void rationalize(Rational& rat) {
	assert(isValid(rat));
	int gcdRat = gcd(rat.nominator, rat.denominator);
	rat.nominator /= gcdRat;
	rat.denominator /= gcdRat;
}

Rational sumRationals(const Rational& lhs, const Rational& rhs) {
	assert(isValid(lhs) && isValid(rhs));

	Rational summedRat{ 
		lhs.nominator * rhs.denominator + rhs.nominator * lhs.denominator,
		lhs.denominator * rhs.denominator };

	rationalize(summedRat);
	return summedRat;
}

int main() {
	Rational a{ 1, 6 };
	Rational b{ 1, 3 };

	Rational sum = sumRationals(a, b);
	printRational(sum);
}