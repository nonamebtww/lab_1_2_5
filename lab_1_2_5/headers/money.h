#pragma once

#include <string>

class Money {
private:
	int first; // nominal
	int second; // count
public:
	Money(int first, int second);

	// Properties
	int GetFirst() const;

	bool SetFirst(int value	);

	int GetSecond() const;

	bool SetSecond(int value);

	int GetTotalAmount() const;

	// Methods
	std::string Statistic() const;

	bool EnoughFor(int amount) const;

	int EnoughForCount(int price) const;

	// Operators
	const int& operator[](int index) const;

	Money& operator++();

	Money& operator--();

	bool operator!() const;

	Money operator+(int value);

	Money operator-(int value);
};