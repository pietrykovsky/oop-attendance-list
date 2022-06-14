#pragma once
#include <string>
class Date
{
	unsigned int day, month, year;

public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);
	bool operator==(Date& date);
	void print();
	std::string toString();
	//setters
	bool setDate(unsigned int day, unsigned int month, unsigned int year);
};

