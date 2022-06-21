#include "AttendanceList.h"
#include <iostream>

AttendanceList::AttendanceList() {
}

AttendanceList::AttendanceList(unsigned int size) {
	this->size = size;
	this->attendance = new bool[size];
	for (int i = 0; i < size; i++)
		attendance[i] = false;
}

AttendanceList::AttendanceList(Date date, unsigned int size) {
	this->date = date;
	this->size = size;
	this->attendance = new bool[size];
	for (int i = 0; i < size; i++)
		attendance[i] = false;
}

//setters
bool AttendanceList::setAttendance(bool attendance, unsigned int id) {
	if (id < size) {
		this->attendance[id] = attendance;
		return 0;
	}
	return 1;
}

bool AttendanceList::setDate(Date date) {
	this->date = date;
	return 0;
}

//getters
bool AttendanceList::getAttendance(unsigned int id) {
	if (id < size)
		return attendance[id];
	return 0;
}

bool* AttendanceList::getList()
{
	return attendance;
}

Date AttendanceList::getDate() {
	return date;
}