#include "Date.h"
#include <iostream>

Date::Date() {
	day = 1;
	month = 1;
	year = 2022;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
	if (day <= 31 && month <= 12 && year <= 2022) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else {
		this->day = 1;
		this->month = 1;
		this->year = 2022;
	}
}

bool Date::operator==(Date& date) {
	if (day == date.day && month == date.month && year == date.year)
		return 1;
	else
		return 0;
}

void Date::print() {
	std::cout << day << "." << month << "." << year << "\n";
}

//setters
bool Date::setDate(unsigned int day, unsigned int month, unsigned int year) {
	if (day <= 31 && month <= 12 && year <= 2022) {
		this->day = day;
		this->month = month;
		this->year = year;
		return 0;
	}
	return 1;
}

std::string Date::toString() {
	std::string date = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
	return date;
}