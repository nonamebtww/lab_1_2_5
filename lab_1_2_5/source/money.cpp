#include <string>
#include <stdexcept>

#include "Money.h"

using namespace std;

// Constructors
Money::Money(int first, int second) : first(first), second(second) { }

// Properties
int Money::GetFirst() const {
	return first;
}

bool Money::SetFirst(int value) {
	if (value < 0) {
		return false;
	}

	first = value;

	return true;
}

int Money::GetSecond() const {
	return second;
}

bool Money::SetSecond(int value) {
	if (value < 0) {
		return false;
	}

	second = value;

	return true;
}

int Money::GetTotalAmount() const {
	return first * second;
}

// Methods
string Money::Statistic() const {
	return first + " x " + second;
}

bool Money::EnoughFor(int amount) const {
	return first * second >= amount;
}

int Money::EnoughForCount(int price) const {
	auto has_amount = first * second;

	return (has_amount - (has_amount % price)) / price;
}

// Operators
const int& Money::operator[](int index) const {
	switch (index) {
	case 1:
		return first;
	case 2:
		return second;
	default:
		throw out_of_range("Unknown index");
	}
}

Money& Money::operator++() {
	++first;
	++second;

	return *this;
}

Money& Money::operator--() {
	if (1 > first || 1 > second) {
		throw invalid_argument("Nominal or count can not be less than 0 or equal 0!");
	}

	--first;
	--second;

	return *this;
}

bool Money::operator!() const {
	return second > 0;
}

Money Money::operator+(int value) {
	return Money(first, second + value);
}

Money Money::operator-(int value) {
	if (value > second) {
		throw invalid_argument("Count can not be less than 0!");
	}

	return Money(first, second - value);
}