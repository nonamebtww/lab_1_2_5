#pragma once

#include <string>
#include <stdexcept>

using namespace std;

class Money {
private:
	int first; // nominal
	int second; // count
public:
	Money(int first, int second) {
		this->first = first;
		this->second = second;
	}

	// Properties
	int GetFirst() const {
		return first;
	}

	bool SetFirst(int value) {
		if (value <= 0) {
			return false;
		}

		first = value;

		return true;
	}


	int GetSecond() const {
		return second;
	}

	bool SetSecond(int value) {
		if (value <= 0) {
			return false;
		}

		second = value;

		return true;
	}

	int GetAmount() const {
		return first * second;
	}

	// Methods
	string Statistic() const {
		return first + " x " + second;
	}

	bool EnoughFor(int amount) const {
		return first * second >= amount;
	}

	int EnoughForCount(int price) const {
		auto has_amount = first * second;

		return (has_amount - (has_amount % price)) / price;
	}

	// Operators
	const int& operator[](int index) const {
		switch (index) {
		case 1:
			return first;
		case 2:
			return second;
		default:
			throw out_of_range("Unknown index");
		}
	}

	Money& operator++() {
		++first;
		++second;

		return *this;
	}

	Money& operator--() {
		if (1 > first || 1 > second) {
			throw invalid_argument("Nominal or count can not be less than 0 or equal 0!");
		}

		--first;
		--second;

		return *this;
	}

	bool operator!() const {
		return second > 0;
	}

	Money operator+(int value) {
		return Money(first, second + value);
	}

	Money operator-(int value) {
		if (value > second) {
			throw invalid_argument("Count can not be less than 0!");
		}

		return Money(first, second - value);
	}
};